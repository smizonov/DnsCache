
#include <gtest/gtest.h>
#include <DnsCache.h>

namespace {

std::string asName(int i) {
    return "name" + std::to_string(i);
}

std::string asIp(int i) {
    return "ip" + std::to_string(i);
}

}

TEST(DnsCache, EmptyCheck)
{
    using namespace network;
    DNSCache cache(1);

    EXPECT_EQ("", cache.resolve("Missing name"));
}

TEST(DnsCache, UpdateCheck)
{
    using namespace network;
    DNSCache cache(1);

    std::string name = "name";
    std::string ip = "ip";
    cache.update(name, ip);
    EXPECT_EQ(ip, cache.resolve(name));
    ip = "updatededIp";
    cache.update(name, ip);
    EXPECT_EQ(ip, cache.resolve(name));
}

TEST(DnsCache, FillCheck)
{
    using namespace network;
    constexpr auto kSize{ 10 };
    DNSCache cache(kSize);

    for (int i = 0; i < kSize; ++i)
    {
        cache.update(asName(i), asIp(i));
    }

    for (int i = 0; i < kSize; ++i)
    {
        EXPECT_EQ(cache.resolve(asName(i)), asIp(i));
    }
}

TEST(DnsCache, OverflowCheck)
{
    using namespace network;
    constexpr auto kSize{ 10 };
    DNSCache cache(kSize);

    auto constexpr kOverflowCount{ 2 * kSize };
    for (int i = 0; i < kOverflowCount; ++i)
    {
        cache.update(asName(i), asIp(i));
    }

    for (int i = (kOverflowCount - kSize); i < kOverflowCount; ++i)
    {
        EXPECT_EQ(cache.resolve(asName(i)), asIp(i));
    }
}
