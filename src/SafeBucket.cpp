#include <SafeBucket.h>

#include <Node.h>
#include <ActualNodesQueue.h>

namespace network
{

BacketSafe::BacketSafe(ActualNodes & parent)
{}

NodePtr BacketSafe::findAndRemoveExpiredUnsafe(std::string const & name)
{
    NodePtr dst{ nullptr };
    for (auto it = nodes_.begin(); it != nodes_.end();)
    {
        if (auto lock = it->lock())
        {
            if (name == lock->name)
            {
                dst = lock;
            }
            ++it;
        }
        else
        {
            it = nodes_.erase(it);
        }
    }
    return dst;
}

void BacketSafe::update(const std::string& name, const std::string& ip)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = findAndRemoveExpiredUnsafe(name))
    {
        node->ip = ip;
        nodesHolder_.push(std::move(node));
        return;
    }

    auto newNode = std::make_shared<Node>(name, ip);
    nodes_.push_back(NodeWeakPtr(newNode));
    nodesHolder_.push(std::move(newNode));
}

std::string BacketSafe::resolve(const std::string& name)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = findAndRemoveExpiredUnsafe(name))
    {
        return node->ip;
        nodesHolder_.push(std::move(node));
    }

    return "";
}
}
