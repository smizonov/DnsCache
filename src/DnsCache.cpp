#include <DnsCache.h>

#include <memory>
#include <mutex>

#include <BucketsStorer.h>
#include <BucketSafe.h>

namespace network
{

DNSCache::DNSCache(size_t max_size)
    : actualData_(max_size)
    , data_(max_size, actualData_)
{}

void DNSCache::update(std::string const & name, std::string const & ip)
{
    data_.get(name).update(name, ip);
}

std::string DNSCache::resolve(const std::string &name)
{
    return data_.get(name).resolve(name);
}

}
