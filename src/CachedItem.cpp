#include <Node.h>

#include <string>

namespace network
{

CachedItem::CachedItem(std::string const & name, std::string const & ip):
    name_(name),
    ip_(ip)
{}

std::string const & CachedItem::ip()
{
    return ip_;
}

std::string const & CachedItem::name()
{
    return name_;
}

void CachedItem::setIp(std::string const & ip)
{
    ip_ = ip;
};

}
