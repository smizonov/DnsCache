#include <ActualNodes.h>
#include <Node.h>

TEST(ActualNodes, Simple)
{
    using namespace network;
    ActualNodes nodes(1);
    std::string name = "name";
    std::string ip = "ip";
    auto node = std::make_shared<Node>(name, ip);
    auto tmp = node;
    nodes.update(std::move(tmp));
    

}