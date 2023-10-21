#include <memory>

namespace network
{

struct Node;
class ActualNodes;
class BacketSafe;
class DNSCache;
using NodePtr = std::shared_ptr<Node>;
using NodeWeakPtr = std::weak_ptr<Node>;

}
