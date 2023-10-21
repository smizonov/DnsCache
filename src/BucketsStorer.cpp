#include <BucketsStorer.h>

#include <BucketSafe.h>

#include <functional>
#include <string>

namespace network
{

BucketsStorer::BucketsStorer(
        size_t size,
        ActualNodes & nodes)
{
    data_.reserve(size);
    for(size_t i = 0; i < size; ++i)
        data_.emplace_back(std::make_unique<BucketSafe>(nodes));
}

BucketSafe &BucketsStorer::get(const std::string &name)
{
    return *data_[std::hash<std::string>{}(name) % data_.size()];
}

}
