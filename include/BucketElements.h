#pragma once
#include <string>
#include <mutex>
#include <vector>
#include <memory>

#include <Fwd.h>

namespace network
{

class BucketElements
{
public:
    NodePtr findUnsafe(std::string const & name);
    void pushUnsafe(NodeWeakPtr const &);

private:
    void removeExpiredEveryNthCall();

private:
    int callCounter{ 0 };
    std::vector<NodeWeakPtr> nodes_;
};

}
