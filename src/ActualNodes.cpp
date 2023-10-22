#include <ActualNodes.h>

#include <algorithm>
#include <cassert>
#include <exception>

#include <Node.h>

namespace network
{

ActualNodes::ActualNodes(size_t size)
    : maxSize_(size)
{
    assert(maxSize_ != 0);
    data_.reserve(maxSize_);
}

void ActualNodes::update(NodePtr && node)
{
    std::lock_guard<std::mutex> lock(m_);

    if (!node)
        throw std::runtime_error("ActualNodes::update: node is nullptr");

    node->setLastUsageIndex(++currentUsageIndex_);

    if (node->storageIndex().has_value() &&
            data_[node->storageIndex().value()] == node)
        return;

    if (maxSize_ > data_.size())
    {
        node->setStorageIndex(data_.size());
        data_.push_back(std::move(node));
    }
    else
    {
        auto oldestUpdatedIt = std::min_element(
                    data_.begin(),
                    data_.end(),
                    []
                    (NodePtr const & lhs, NodePtr const & rhs)
                    {
                        return lhs->lastUsageIndex() < rhs->lastUsageIndex();
                    });
        node->setStorageIndex(oldestUpdatedIt - data_.begin());
        *oldestUpdatedIt = std::move(node);
    }
}


}
