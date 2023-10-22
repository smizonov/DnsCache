#include <Node.h>

#include <string>

namespace network
{

Node::Node(CachedItem && obj):
    cachedItem_(std::move(obj))
{}

CachedItem &Node::cachedItem()
{
    return cachedItem_;
}

uint64_t Node::lastUsageIndex()
{
    return lastUsageIndex_;
}

void Node::setLastUsageIndex(int64_t val)
{
    lastUsageIndex_ = val;
}

std::optional<size_t> Node::storageIndex()
{
    return storageIndex_;
}

void Node::setStorageIndex(size_t index)
{
    storageIndex_ = index;
}

}
