#include <ActualNodes.h>

#include <algorithm>
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
    if (!node)
        throw std::runtime_error("ActualNodes::update: node is nullptr");

    std::lock_guard<std::mutex> lock(m_);
    auto minLastUsageIndex{ 0 };
    auto minLastUsageIt{ data_.begin() };
    auto foundNodeIt{ data_.end() };
    for (auto it = data_.begin(); it != data_.end(); ++it)
    {
        if (*it == node)
        {
            foundNodeIt = it;
            break;
        }

        if (it->get()->lastUsageIndex < minLastUsageIndex)
        {
            minLastUsageIndex = it->get()->lastUsageIndex;
            minLastUsageIt = it;
        }
    }

    node->lastUsageIndex = ++currentUsageIndex_;
    if (data_.end() == foundNodeIt)
    {
        if (maxSize_ > data_.size())
            data_.push_back(std::move(node));
        else
            *minLastUsageIt = std::move(node);
    }
}


}
