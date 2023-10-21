
set(Headers
    ../include/ActualNodes.h
    ../include/DnsCache.h
    ../include/BucketSafe.h
    ../include/BucketElements.h
    ../include/BucketsStorer.h
    ../include/Node.h)

set(Sources
    ActualNodes.cpp
    DnsCache.cpp
    BucketSafe.cpp
    BucketElements.cpp
    BucketsStorer.cpp
    Node.cpp)

add_library(DnsCache
    ${Sources} ${Headers}
)

target_include_directories(DnsCache PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
