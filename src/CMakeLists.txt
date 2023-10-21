add_library(DnsCacheLib
    ActualNodes.cpp
    DnsCache.cpp
    BucketSafe.cpp
    BucketElements.cpp
    BucketsStorer.cpp
    Node.cpp
)

target_include_directories(DnsCacheLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)