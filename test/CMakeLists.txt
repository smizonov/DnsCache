# Create an executable for your tests

set(This DnsCacheTests)

set(Headers
    include/Utils.h)

set(Sources
    DnsCacheUnit.cpp
    DnsCacheStress.cpp
    Utils.cpp)

add_executable(${This} ${Sources} ${Headers})

find_package(GTest REQUIRED)

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link the test executable with Google Test and your project's source code
target_link_libraries(${This}  PUBLIC GTest::GTest GTest::Main DnsCache)

add_test(
    NAME ${This}
    COMMAND ${This}
)

# add_test(NAME MyProjectTests COMMAND MyProjectTests)

# # Register the test with CTest
# include(GoogleTest)
# gtest_discover_tests(MyProjectTests)
