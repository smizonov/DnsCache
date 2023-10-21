#include <BucketSafe.h>

#include <Node.h>
#include <ActualNodes.h>

namespace network
{

BucketSafe::BucketSafe(ActualNodes & obj)
    : actualData_(obj)
{}

void BucketSafe::update(std::string const & name, std::string const & ip)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = internalNodes_.find(name))
    {
        node->setIp(ip);
        actualData_.update(std::move(node));
        return;
    }

    auto newNode{ std::make_shared<Node>(name, ip) };
    internalNodes_.push(NodeWeakPtr(newNode));
    actualData_.update(std::move(newNode));
}

std::string BucketSafe::resolve(const std::string& name)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = internalNodes_.find(name))
    {
        auto tmp{ node->ip() };
        actualData_.update(std::move(node));
        return tmp;
    }

    return "";
}

}
