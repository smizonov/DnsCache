#pragma once

#include <string>

#include <ActualNodes.h>
#include <BucketsStorer.h>

namespace network
{

class DNSCache
{
public:
    static void create(size_t max_size);
    static DNSCache & getInstance();

protected:
    explicit DNSCache(size_t max_size);

private:
    static DNSCache & getInstanceImpl(size_t max_size = 0);

public:
    void update(const std::string& name, const std::string& ip);
    std::string resolve(const std::string& name);

private:
    ActualNodes actualData_;
    BucketsStorer dataForSearching_;
};

}
