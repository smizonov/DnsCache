#include <ActualNodesQueue.h>

#include <algorithm>

#include <Node.h>

namespace network
{


ActualNodes::ActualNodes(size_t size)
{}

//void ActualNodes::push(NodePtr && node)
//{
//    std::lock_guard<std::mutex> lock(m_);
//    auto foundIt = std::lower_bound(actualData_.begin(), actualData_.end(), node,
//                                    [](NodePtr const & lhs, NodePtr const & rhs)
//    {
//            return lhs->index >= rhs->index;
//});

//    node->index = ++usageIndex_;
//    if (*foundIt != node)
//        actualData_.push_front(std::move(node));
//    else
//        std::rotate(actualData_.begin(), foundIt, std::next(foundIt));

//}

void ActualNodes::push(NodePtr && node)
{
    std::lock_guard<std::mutex> lock(m_);
    auto minUsageIndex{ 0 };
    auto minUsageIt{ actualData_.begin() };
    auto foundNodeIt{ actualData_.begin() };
    for (; foundNodeIt != actualData_.end(); ++ foundNodeIt)
    {
        if (*foundNodeIt == node)
            break;

        if (foundNodeIt->get()->index < minUsageIndex)
        {
            minUsageIndex = foundNodeIt->get()->index;
            minUsageIt = foundNodeIt;
        }
    }

    node->index = ++usageIndex_;
    if (actualData_.end() == foundNodeIt)
    {
        *minUsageIt = std::move(node);
    }
}


}
