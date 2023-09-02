//
// server.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include <functional>
#include <memory>

#include "connection.hpp"
#include "connection_manager.hpp"
#include "request_handler.hpp"
#include "reply.hpp"
#include "request.hpp"
#include "request_cb_manager.hpp"

namespace http {
namespace server {

// struct request;
// struct reply;

/// The top-level class of the HTTP server.
class server
{
public:
  server(const server&) = delete;
  server& operator=(const server&) = delete;

  /// Construct the server to listen on the specified TCP address and port, and
  /// serve up files from the given directory.
  explicit server(const std::string& address, const std::string& port,
      const std::string& doc_root);

  /// Run the server's io_context loop.
  void run();

  // register get route
  void get(const std::string path, std::function<void(const request& req, reply& rep)>);
  
private:
  /// Perform an asynchronous accept operation.
  void do_accept();

  /// Wait for a request to stop the server.
  void do_await_stop();

  /// The io_context used to perform asynchronous operations.
  boost::asio::io_context io_context_;

  /// The signal_set is used to register for process termination notifications.
  boost::asio::signal_set signals_;

  /// Acceptor used to listen for incoming connections.
  boost::asio::ip::tcp::acceptor acceptor_;

  /// The connection manager which owns all live connections.
  connection_manager connection_manager_;

  // Get request manager
  std::shared_ptr<request_cb_manager> get_request_cb_manager_ptr_;

  /// The handler for all incoming requests.
  request_handler request_handler_;

};

} // namespace server
} // namespace http

#endif // HTTP_SERVER_HPP
