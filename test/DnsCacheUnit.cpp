
#include <gtest/gtest.h>
#include <DnsCache.h>
#include <Utils.h>

TEST(DnsCacheUnit, NonexsistanceCheck)
{
    using namespace network;
    utils::DnsCacheMock cache(1);

    auto str = "str";
    EXPECT_EQ("", cache.resolve(str));
}

TEST(DnsCacheUnit, UpdateCheck)
{
    using namespace network;
    utils::DnsCacheMock cache(1);

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
    utils::DnsCacheMock cache(kSize);

    for (int i = 0; i < kSize; ++i)
    {
        cache.update(utils::asName(i), utils::asIp(i));
    }

    for (int i = 0; i < kSize; ++i)
    {
        EXPECT_EQ(cache.resolve(utils::asName(i)), utils::asIp(i));
    }
}

TEST(DnsCacheUnit, OverflowCheck)
{
    using namespace network;
    constexpr auto kSize{ 10 };
    utils::DnsCacheMock cache(kSize);

    auto constexpr kOverflowCount{ 2 * kSize };
    for (int i = 0; i < kOverflowCount; ++i)
    {
        cache.update(utils::asName(i), utils::asIp(i));
    }

    for (int i = (kOverflowCount - kSize); i < kOverflowCount; ++i)
    {
        EXPECT_EQ(cache.resolve(utils::asName(i)), utils::asIp(i));
    }
}
