#include <DnsCache.h>

#include <BucketsStorer.h>
#include <Bucket.h>

namespace network
{

void DNSCache::create(size_t max_size)
{
    getInstanceImpl(max_size);
}

DNSCache & DNSCache::getInstance()
{
    return getInstanceImpl();
}

DNSCache::DNSCache(size_t max_size)
    : actualData_(ActualNodes(max_size))
    , dataForSearching_(max_size, actualData_)
{}

DNSCache & DNSCache::getInstanceImpl(size_t max_size)
{
    static DNSCache cache(max_size);
    return cache;
}

void DNSCache::update(std::string const & name, std::string const & ip)
{
    dataForSearching_.get(name).update(name, ip);
}

std::string DNSCache::resolve(const std::string &name)
{
    return dataForSearching_.get(name).resolve(name);
}

}
