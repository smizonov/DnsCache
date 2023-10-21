#include <Node.h>

#include <string>

namespace network
{

Node::Node(std::string const & name, std::string const & ip):
    name_(name),
    ip_(ip)
{}

uint64_t Node::lastUsageIndex()
{
    return lastUsageIndex_;
}

std::string const & Node::ip()
{
    return ip_;
}

const std::string &Node::name()
{
    return name_;
}

void Node::setLastUsageIndex(int64_t val)
{
    lastUsageIndex_ = val;
}

void Node::setIp(std::string const & ip)
{
    ip_ = ip;
};

}
