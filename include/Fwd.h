#include <memory>

namespace network
{

struct Node;
class ActualNodes;
class BucketSafe;
class DNSCache;
class BucketElements;
using NodePtr = std::shared_ptr<Node>;
using NodeWeakPtr = std::weak_ptr<Node>;

}
