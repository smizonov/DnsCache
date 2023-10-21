#pragma once

#include <string>

namespace network
{

struct Node
{
    int64_t lastUsageIndex{ 0 };
    std::string name;
    std::string ip;
};

}
