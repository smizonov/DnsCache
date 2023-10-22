#pragma once

#include <string>
#include <mutex>

#include <BucketElements.h>
#include <Fwd.h>

namespace network
{

class Bucket
{
public:
    Bucket(ActualNodes &);

    Bucket(Bucket const &) = delete;
    Bucket(Bucket &&) = delete;
    Bucket& operator=(Bucket const &) = delete;
    Bucket& operator=(Bucket &&) = delete;
    ~Bucket() = default;

public:
    void update(std::string const & name, std::string const & ip);
    std::string resolve(std::string const & name);

private:
    std::mutex m_;
    BucketElements internalNodes_;
    ActualNodes & actualData_;
};

}
