#include <iostream>
#include <tuple>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "xml2json.h"

namespace pt = boost::property_tree;
namespace xml_parser = pt::xml_parser;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage:" << argv[0] << " <src> <dest>" << std::endl;
        exit(-1);
    }
    const std::string srcXml = argv[1];
    const std::string destJson = argv[2];

    pt::ptree xmlTree;
    xml_parser::read_xml(srcXml, xmlTree);
    pt::ptree jsonTree;

    XMLTreeToJsonTree(xmlTree, jsonTree);

    pt::json_parser::write_json(destJson, jsonTree);
    return 0;
}
