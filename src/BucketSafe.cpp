#include <BucketSafe.h>

#include <Node.h>
#include <ActualNodes.h>

namespace network
{

BucketSafe::BucketSafe(ActualNodes & obj)
    : actualNodes_(obj)
{}

void BucketSafe::update(const std::string& name, const std::string& ip)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = internalNodes_.findUnsafe(name))
    {
        node->ip = ip;
        actualNodes_.update(std::move(node));
        return;
    }

    auto newNode{ std::make_shared<Node>(name, ip) };
    internalNodes_.pushUnsafe(NodeWeakPtr(newNode));
    actualNodes_.update(std::move(newNode));
}

std::string BucketSafe::resolve(const std::string& name)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = internalNodes_.findUnsafe(name))
    {
        actualNodes_.update(std::move(node));
        return node->ip;
    }

    return "";
}

}
