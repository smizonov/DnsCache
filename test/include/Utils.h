#pragma once

#include <DnsCache.h>

namespace network {
namespace utils {

std::string asName(int i, std::string const & suffix = "");
std::string asIp(int i, std::string const & suffix = "");

class DnsCacheMock:
        public network::DNSCache
{
public:
    DnsCacheMock(size_t maxSize):
        network::DNSCache(maxSize)
    {};
};

}
}
