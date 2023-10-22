#pragma once
#include <memory>
#include <mutex>
#include <vector>

#include <Fwd.h>

namespace network
{

class ActualNodes
{
public:
    ActualNodes(size_t size);
    void update(NodePtr && node);

private:
    std::mutex m_;
    size_t const maxSize_;
    std::vector<NodePtr> data_;
    uint64_t currentUsageIndex_{ 0 };
};

}
