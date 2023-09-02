#include <iostream>
#include <tuple>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "xml2json.h"

namespace pt = boost::property_tree;
namespace xml_parser = pt::xml_parser;

void XMLTreeToJsonTree(pt::ptree const &xmlTree, pt::ptree &jsonTree)
{
    if (xmlTree.size() == 0)
    {
        // Found string value with no children
        auto const &value = xmlTree.data();
        jsonTree.data() = value;
    }

    for (auto const &it : xmlTree)
    {
        pt::ptree newChild;
        XMLTreeToJsonTree(it.second, newChild);
        jsonTree.add_child(it.first, newChild);
    }
}