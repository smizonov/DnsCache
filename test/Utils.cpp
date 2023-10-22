#pragma once

#include <Utils.h>

namespace network {
namespace utils {

std::string asName(int i) {
    return "name" + std::to_string(i);
}

std::string asIp(int i) {
    return "ip" + std::to_string(i);
}

}
}
