#pragma once
#include <string>
#include <mutex>
#include <list>
#include <memory>

#include <Fwd.h>
#include <BucketElements.h>

namespace network
{

class BucketSafe
{
public:
    BucketSafe(ActualNodes &);

    BucketSafe(BucketSafe const &) = delete;
    BucketSafe(BucketSafe &&) = delete;

public:
    void update(std::string const & name, std::string const & ip);
    std::string resolve(std::string const & name);

private:
    std::mutex m_;
    BucketElements internalNodes_;
    ActualNodes & actualNodes_;
};

}
