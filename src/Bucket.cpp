#include <Bucket.h>

#include <ActualNodes.h>
#include <CachedItem.h>
#include <Node.h>

namespace network
{

Bucket::Bucket(ActualNodes & obj)
    : actualData_(obj)
{}

void Bucket::update(std::string const & name, std::string const & ip)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = internalNodes_.find(name))
    {
        node->cachedItem().setIp(ip);
        actualData_.update(std::move(node));
        return;
    }

    auto node{ std::make_shared<Node>(CachedItem(name, ip)) };
    internalNodes_.push(NodeWeakPtr(node));
    actualData_.update(std::move(node));
}

std::string Bucket::resolve(const std::string& name)
{
    std::lock_guard<std::mutex> lock(m_);

    if (auto node = internalNodes_.find(name))
    {
        auto tmp{ node->cachedItem().ip() };
        actualData_.update(std::move(node));
        return tmp;
    }

    return "";
}

}
