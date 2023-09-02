//
// server.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef REQUEST_CB_MANAGER_HPP
#define REQUEST_CB_MANAGER_HPP

#include <functional>
#include <unordered_map>

#include "reply.hpp"
#include "request.hpp"

namespace http {
namespace server {

class request_cb_manager 
{
public:
    request_cb_manager();
    bool call_cb(std::string path, const request& req, reply& rep);
    void reg(std::string path, std::function<void(const request& req, reply& rep)> cb);
private:
    std::unordered_map<
        std::string, 
        std::function<void(const request& req, reply& rep)>
    > route_cb_map_;
};

} // namespace server
} // namespace http


#endif // REQUEST_CB_MANAGER_HPP
