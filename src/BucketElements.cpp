#include <BucketElements.h>

#include <Node.h>
#include <ActualNodes.h>

namespace network
{

NodePtr BucketElements::findUnsafe(std::string const & name)
{
    removeExpiredEveryNthCall();
    for (auto const & obj : nodes_)
    {
        if (auto locked = obj.lock(); locked && name == locked->name)
            return locked;
    }
    return nullptr;
}

void BucketElements::pushUnsafe(NodeWeakPtr const & obj)
{
    removeExpiredEveryNthCall();
    nodes_.push_back(obj);
}

void BucketElements::removeExpiredEveryNthCall()
{
    static constexpr auto N{ 20 };
    if (++callCounter % N)
    {
        nodes_.erase(std::remove_if(nodes_.begin(),
                                    nodes_.end(),
                                    [](NodeWeakPtr const & obj)
                                    {
                                        return obj.expired();
                                    }));
        callCounter = 0;
    }
}

}
