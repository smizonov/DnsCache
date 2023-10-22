find_package(GTest REQUIRED)

set(This DnsCacheTests)

set(Headers
    include/Utils.h)

set(Sources
    DnsCacheUnit.cpp
    DnsCacheStress.cpp
    Utils.cpp)

add_executable(${This} ${Sources} ${Headers})

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${This}  PUBLIC GTest::GTest GTest::Main DnsCache)

add_test(
    NAME ${This}
    COMMAND ${This}
)
