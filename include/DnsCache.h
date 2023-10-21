#pragma once

#include <string>

#include <ActualNodes.h>
#include <BucketsStorer.h>
#include <Fwd.h>

namespace network
{

class DNSCache
{
public:
    explicit DNSCache(size_t max_size);
    void update(const std::string& name, const std::string& ip);
    std::string resolve(const std::string& name);

private:
    ActualNodes actualData_;
    BucketsStorer data_;
};

}
