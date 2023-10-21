#include <iostream>
#include <boost/optional.hpp>
#include <vector>
#include <list>
#include <mutex>
#include <map>
#include <atomic>
#include <algorithm>
#include <boost/circular_buffer.hpp>

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <mutex>
#include <memory>

class DNSCache;

using UsageIndex = std::atomic<int64_t>;

struct Node
{
    int64_t index{ 0 };
    std::string name;
    std::string ip;
};

using NodePtr = std::shared_ptr<Node>;
using NodeWeakPtr = std::weak_ptr<Node>;

class ActualNodesQueue
{
public:
    ActualNodesQueue(size_t size);
    void push(NodePtr && node)
    {
        std::lock_guard<std::mutex> lock(m_);
        auto foundIt = std::lower_bound(actualData_.begin(), actualData_.end(), node,
                         [](NodePtr const & lhs, NodePtr const & rhs)
        {
            return lhs->index >= rhs->index;
        });

        node->index = ++usageIndex_;
        if (*foundIt != node)
            actualData_.push_front(std::move(node));
        else
            std::rotate(actualData_.begin(), foundIt, std::next(foundIt));

    }

private:
//    std::map<>
    boost::circular_buffer<NodePtr> actualData_;
    std::mutex m_;
    size_t maxSize_;
    int64_t usageIndex_{ 1 };
};

class BacketSafe
{
    BacketSafe(ActualNodesQueue & parent);

    NodePtr findAndRemoveExpiredUnsafe(std::string const & name)
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

    void update(const std::string& name, const std::string& ip)
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
    std::string resolve(const std::string& name)
    {
        std::lock_guard<std::mutex> lock(m_);

        if (auto node = findAndRemoveExpiredUnsafe(name))
        {
            return node->ip;
            nodesHolder_.push(std::move(node));
        }

        return "";
    }
private:
    std::list<NodeWeakPtr> nodes_;
    std::mutex m_;
    ActualNodesQueue & nodesHolder_;
};

using namespace std;


class DNSCache
{
public:
    explicit DNSCache(size_t max_size);
    void update(const std::string& name, const std::string& ip);
    std::string resolve(const std::string& name);

private:
    ActualNodesQueue actualData_;
    std::unordered_map<std::string, BacketSafe> data_;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

