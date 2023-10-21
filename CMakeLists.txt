cmake_minimum_required(VERSION 3.5)

project(DnsCache LANGUAGES CXX)

set(IncludeDir ${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/ActualNodesQueue.cpp
    src/DnsCache.cpp
    src/SafeBucket.cpp
    main.cpp
    ${IncludeDir}/Fwd.h
    ${IncludeDir}/ActualNodesQueue.h
    ${IncludeDir}/DnsCache.h
    ${IncludeDir}/SafeBucket.h
    ${IncludeDir}/Node.h
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DnsCache ${SOURCES})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${IncludeDir}
)
