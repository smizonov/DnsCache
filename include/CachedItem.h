#pragma once

#include <string>

namespace network
{

struct CachedItem
{
public:
    CachedItem(std::string const & name, std::string const & ip);

    CachedItem(CachedItem &&) = default;
    CachedItem(CachedItem const &) = delete;
    CachedItem& operator=(CachedItem const &) = delete;
    CachedItem& operator=(CachedItem &&) = delete;
    ~CachedItem() = default;

public:
    std::string const & ip();
    std::string const & name();
    void setIp(std::string const & ip);

private:
    std::string name_;
    std::string ip_;
};

}
