#pragma once

#include <DnsCache.h>

namespace network {
namespace utils {

std::string asName(int i);
std::string asIp(int i);

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
