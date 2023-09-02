
#include <functional>
#include <unordered_map>
#include <iostream>
#include "request_cb_manager.hpp"
#include "reply.hpp"
#include "request.hpp"

namespace http {
namespace server {

request_cb_manager::request_cb_manager() : route_cb_map_() {}

// Returns if callback was called or not
bool request_cb_manager::call_cb(std::string path, const request& req, reply& rep) {
    std::cout << this << std::endl;
    std::cout << "==> call_cb path:" << path << std::endl;
    std::cout << "==> call_cb map size:" << route_cb_map_.size() << std::endl;

    if (route_cb_map_.find(path) == route_cb_map_.end()) {
        return false;
    }

    auto const& cb = route_cb_map_.at(path);
    cb(req, rep);
    return true;
}

void request_cb_manager::reg(std::string path, std::function<void(const request& req, reply& rep)> cb) {
    std::cout << this << std::endl;
    std::cout << "==> registering path:" << path << std::endl;
    std::cout << "==> registering map size:" << route_cb_map_.size() << std::endl;

    route_cb_map_[path] = cb;

    std::cout << "==> registering map size:" << route_cb_map_.size() << std::endl;
}


} // namespace server
} // namespace http
