#include <Utils.h>

namespace network {
namespace utils {

std::string asName(int i, std::string const & suffix)
{
    return "name" + std::to_string(i) + suffix;
}

std::string asIp(int i, std::string const & suffix)
{
    return "ip" + std::to_string(i) + suffix;
}

}
}
