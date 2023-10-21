#include <string>
#include <mutex>
#include <list>
#include <memory>

#include <Fwd.h>

namespace network
{

class BacketSafe
{
public:
    BacketSafe(ActualNodes & parent);

public:
    void update(const std::string& name, const std::string& ip);
    std::string resolve(const std::string& name);

private:
    NodePtr findAndRemoveExpiredUnsafe(std::string const & name);

private:
    std::mutex m_;
    std::list<NodeWeakPtr> nodes_;
    ActualNodes & nodesHolder_;
};

}
