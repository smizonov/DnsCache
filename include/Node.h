#pragma once

#include <string>

namespace network
{

struct Node
{
    Node(std::string const & name, std::string const & ip):
        name(name),
        ip(ip)
    {};
    std::string name;
    std::string ip;
    int64_t lastUsageIndex{ 0 };
};

}
