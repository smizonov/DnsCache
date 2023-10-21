cmake_minimum_required(VERSION 3.5)

project(DnsCache LANGUAGES CXX)

set(IncludeDir ${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/ActualNodes.cpp
    src/DnsCache.cpp
    src/BucketSafe.cpp
    src/BucketElements.cpp
    src/BucketsStorer.cpp
    main.cpp
    ${IncludeDir}/BucketsStorer.h
    ${IncludeDir}/Fwd.h
    ${IncludeDir}/ActualNodes.h
    ${IncludeDir}/DnsCache.h
    ${IncludeDir}/BucketSafe.h
    ${IncludeDir}/BucketElements.h
    ${IncludeDir}/Node.h
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DnsCache ${SOURCES})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${IncludeDir}
)
