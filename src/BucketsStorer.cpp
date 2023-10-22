#include <BucketsStorer.h>

#include <Bucket.h>

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
        data_.emplace_back(std::make_unique<Bucket>(nodes));
}

Bucket &BucketsStorer::get(const std::string &name)
{
    return *data_[std::hash<std::string>{}(name) % data_.size()];
}

}
