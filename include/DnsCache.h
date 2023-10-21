#include <string>
#include <unordered_map>

#include <ActualNodesQueue.h>
#include <Fwd.h>

namespace network
{

class DNSCache
{
public:
    explicit DNSCache(size_t max_size);
    void update(const std::string& name, const std::string& ip);
    std::string resolve(const std::string& name);

private:
    ActualNodes actualData_;
    std::unordered_map<std::string, BacketSafe> data_;
};

}
