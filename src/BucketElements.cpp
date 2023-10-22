#include <BucketElements.h>

#include <algorithm>

#include <Node.h>
#include <ActualNodes.h>

namespace network
{

NodePtr BucketElements::find(std::string const & name)
{
    removeExpiredEveryNthCall();
    for (auto const & obj : nodes_)
    {
        if (auto locked = obj.lock(); locked && name == locked->cachedItem().name())
            return locked;
    }
    return nullptr;
}

void BucketElements::push(NodeWeakPtr const & obj)
{
    removeExpiredEveryNthCall();
    nodes_.push_back(obj);
}

void BucketElements::removeExpiredEveryNthCall()
{
    static constexpr auto N{ 20 };
    if (++callCounter_ % N == 0)
    {
        nodes_.erase(std::remove_if(
                         nodes_.begin(),
                         nodes_.end(),
                         [](NodeWeakPtr const & obj)
                         {
                             return obj.expired();
                         }),
                nodes_.end());
        callCounter_ = 0;
    }
}

}
