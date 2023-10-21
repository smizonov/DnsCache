#include <memory>
#include <mutex>
#include <vector>

#include <boost/circular_buffer.hpp>

#include <Fwd.h>

namespace network
{

class ActualNodes
{
public:
    ActualNodes(size_t size);
    void push(NodePtr && node);

private:
//    boost::circular_buffer<NodePtr> actualData_;
    std::vector<NodePtr> actualData_;
    std::mutex m_;
    size_t maxSize_;
    int64_t usageIndex_{ 1 };
};

}
