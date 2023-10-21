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
    actualData_.reserve(maxSize_);
}

void ActualNodes::update(NodePtr && node)
{
    if (!node)
        throw std::runtime_error("ActualNodes::update: node is nullptr");

    std::lock_guard<std::mutex> lock(m_);
    auto minLastUsageIndex{ 0 };
    auto minLastUsageIt{ actualData_.begin() };
    auto foundNodeIt{ actualData_.end() };
    for (auto it = actualData_.begin(); it != actualData_.end(); ++it)
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
    if (actualData_.end() == foundNodeIt)
    {
        if (maxSize_ < actualData_.size())
            actualData_.push_back(std::move(node));
        else
            *minLastUsageIt = std::move(node);
    }
}


}
