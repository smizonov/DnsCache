#pragma once

#include <string>
#include <optional>

#include <Fwd.h>
#include <CachedItem.h>

namespace network
{

struct Node
{
public:
    Node(CachedItem &&);

    Node(Node &&) = default;
    Node(Node const &) = delete;
    Node& operator=(Node const &) = delete;
    Node& operator=(Node &&) = delete;
    ~Node() = default;

public:
    CachedItem & cachedItem();

    uint64_t lastUsageIndex();
    void setLastUsageIndex(int64_t val);
    std::optional<size_t> storageIndex();
    void setStorageIndex(size_t);

private:
    CachedItem cachedItem_;
    uint64_t lastUsageIndex_{ 0 };
    std::optional<size_t> storageIndex_;
};

}
