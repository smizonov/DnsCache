#pragma once

#include <string>

namespace network
{

struct Node
{
public:
    Node(std::string const & name, std::string const & ip);
    Node(Node const &) = delete;
    Node(Node &&) = delete;

public:
    uint64_t lastUsageIndex();
    std::string const & ip();
    std::string const & name();
    void setLastUsageIndex(int64_t val);
    void setIp(std::string const & ip);

private:
    std::string name_;
    std::string ip_;
    uint64_t lastUsageIndex_{ 0 };
};

}
