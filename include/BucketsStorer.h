#pragma once
#include <vector>
#include <Fwd.h>
#include <BucketSafe.h>

namespace network
{

class BucketsStorer
{
public:
    BucketsStorer(size_t size, ActualNodes &);
    BucketSafe & get(std::string const & name);

private:
    std::vector<std::unique_ptr<BucketSafe>> data_;
};

}
