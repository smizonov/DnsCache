cmake_minimum_required(VERSION 3.15)

project(DnsCache)

# Set project-wide properties and find dependencies here
# (e.g., setting C++ standard, finding libraries)

# Add the include directory if you have public headers
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(GTest REQUIRED)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
