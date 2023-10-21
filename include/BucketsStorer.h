#pragma once
#include <vector>
#include <Fwd.h>

namespace network
{

class BucketsStorer
{
public:
    BucketsStorer(size_t size);
    BucketSafe & get(std::string const & name);

private:
    std::vector<BucketSafe> data_;
};

}
