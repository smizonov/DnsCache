
#include <gtest/gtest.h>
#include <DnsCache.h>

namespace {

std::string asName(int i) {
    return "name" + std::to_string(i);
}

std::string asIp(int i) {
    return "ip" + std::to_string(i);
}


class DnsCacheMock:
        public network::DNSCache
{
public:
    DnsCacheMock(size_t maxSize):
        network::DNSCache(maxSize)
    {};
};

}

TEST(DnsCacheUnit, EmptyCheck)
{
    using namespace network;
    DnsCacheMock cache(1);

    auto str = "str";
    EXPECT_EQ("", cache.resolve(str));
}

TEST(DnsCacheUnit, UpdateCheck)
{
    using namespace network;
    DnsCacheMock cache(1);

    std::string name = "name";
    std::string ip = "ip";
    cache.update(name, ip);
    EXPECT_EQ(ip, cache.resolve(name));
    ip = "updatededIp";
    cache.update(name, ip);
    EXPECT_EQ(ip, cache.resolve(name));
}

TEST(DnsCacheUnit, FillCheck)
{
    using namespace network;
    constexpr auto kSize{ 10 };
    DnsCacheMock cache(kSize);

    for (int i = 0; i < kSize; ++i)
    {
        cache.update(asName(i), asIp(i));
    }

    for (int i = 0; i < kSize; ++i)
    {
        EXPECT_EQ(cache.resolve(asName(i)), asIp(i));
    }
}

TEST(DnsCacheUnit, OverflowCheck)
{
    using namespace network;
    constexpr auto kSize{ 10 };
    DnsCacheMock cache(kSize);

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
