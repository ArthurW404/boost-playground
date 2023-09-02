#include <iostream>
#include <tuple>
#include <boost/property_tree/ptree.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>

#include "xml2json.h"

using boost::asio::ip::tcp;

namespace pt = boost::property_tree;

class tcp_connection
    : public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_context &io_context)
    {
        return pointer(new tcp_connection(io_context));
    }

    tcp::socket &socket()
    {
        return socket_;
    }

    void start()
    {
        message_ = std::string(8, ' ');
        socket_.async_read_some(boost::asio::buffer(message_),
                                boost::bind(&tcp_connection::initial_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }

private:
    tcp_connection(boost::asio::io_context &io_context)
        : socket_(io_context)
    {
    }

    void initial_read(const boost::system::error_code & /*error*/,
                      size_t bytes)
    {
        std::cout << bytes << std::endl;
        auto const size = std::stoi(message_);
        std::cout << message_ << std::endl;

        std::cout << size << std::endl;
        // We expect xml file to be of size n
        message_ = std::string(size, ' ');

        socket_.async_read_some(boost::asio::buffer(message_),
                                boost::bind(&tcp_connection::read_xml, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }

    void read_xml(const boost::system::error_code & /*error*/,
                  size_t bytes)
    {
        std::cout << bytes << std::endl;
        std::cout << message_ << std::endl;
        auto messageStream = std::istringstream(message_);

        boost::property_tree::ptree xmlTree;
        boost::property_tree::ptree jsonTree;
        boost::property_tree::xml_parser::read_xml(messageStream, xmlTree);

        XMLTreeToJsonTree(xmlTree, jsonTree);
        auto outMessageStream = std::ostringstream();

        boost::property_tree::json_parser::write_json(outMessageStream, jsonTree);

        message_ = outMessageStream.str();

        boost::asio::async_write(socket_, boost::asio::buffer(message_),
                                 boost::bind(&tcp_connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }

    void handle_write(const boost::system::error_code & /*error*/,
                      size_t bytes)
    {
    }

    tcp::socket socket_;
    std::string message_;
};

class tcp_server
{
public:
    tcp_server(boost::asio::io_context &io_context)
        : io_context_(io_context),
          acceptor_(io_context, tcp::endpoint(tcp::v4(), 3000))
    {
        start_accept();
    }

private:
    void start_accept()
    {
        tcp_connection::pointer new_connection =
            tcp_connection::create(io_context_);

        acceptor_.async_accept(new_connection->socket(),
                               boost::bind(&tcp_server::handle_accept, this, new_connection,
                                           boost::asio::placeholders::error));
    }

    void handle_accept(tcp_connection::pointer new_connection,
                       const boost::system::error_code &error)
    {
        if (!error)
        {
            new_connection->start();
        }

        start_accept();
    }

    boost::asio::io_context &io_context_;
    tcp::acceptor acceptor_;
};

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_context io_context;
        tcp_server server(io_context);
        io_context.run();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
