#pragma once

#include <string>
#include <vector>

#include <Fwd.h>

namespace network
{

class BucketElements
{
public:
    NodePtr find(std::string const & name);
    void push(NodeWeakPtr const &);

private:
    void removeExpiredEveryNthCall();

private:
    int callCounter_{ 0 };
    std::vector<NodeWeakPtr> nodes_;
};

}
