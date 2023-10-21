#include <BucketsStorer.h>


#include <functional>
#include <string>
#include <unordered_map>

namespace network
{

BucketsStorer::BucketsStorer(size_t size)
    : data_(size)
{
}

BucketSafe &BucketsStorer::get(const std::string &name)
{
    return data_[std::hash<std::string>{}(name) % data_.size()];
}

}
