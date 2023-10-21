#include <DnsCache.h>

#include <BucketsStorer.h>
#include <BucketSafe.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <mutex>
#include <memory>


namespace network
{

DNSCache::DNSCache(size_t max_size)
    : actualData_(max_size)
    , data_(max_size)
{
}

void DNSCache::update(std::string const & name, std::string const & ip)
{
    data_.get(name).update(name, ip);
}

std::string DNSCache::resolve(const std::string &name)
{
    return data_.get(name).resolve(name);
}


}
