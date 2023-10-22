#pragma once
#include <vector>
#include <string>

#include <Fwd.h>
#include <Bucket.h>

namespace network
{

class BucketsStorer
{
public:
    BucketsStorer(size_t size, ActualNodes &);
    Bucket & get(std::string const & name);

private:
    std::vector<std::unique_ptr<Bucket>> data_;
};

}
