#include <memory>

namespace network
{

class ActualNodes;
class Bucket;
class BucketsStorer;
class DNSCache;
class BucketElements;
class CachedItem;

struct Node;
using NodePtr = std::shared_ptr<Node>;
using NodeWeakPtr = std::weak_ptr<Node>;

}
