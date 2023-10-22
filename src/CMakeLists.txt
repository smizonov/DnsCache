set(Headers
    ../include/ActualNodes.h
    ../include/DnsCache.h
    ../include/Bucket.h
    ../include/BucketElements.h
    ../include/BucketsStorer.h
    ../include/Node.h
    ../include/Fwd.h
    ../include/CachedItem.h)

set(Sources
    ActualNodes.cpp
    DnsCache.cpp
    Bucket.cpp
    BucketElements.cpp
    BucketsStorer.cpp
    Node.cpp
    CachedItem.cpp)

add_library(DnsCache
    ${Sources} ${Headers}
)

target_include_directories(DnsCache PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
