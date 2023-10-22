
//#include <gtest/gtest.h>
//#include <DnsCache.h>

//#include <thread>

//namespace {

//std::string asName(int i) {
//    return "name" + std::to_string(i);
//}

//std::string asIp(int i) {
//    return "ip" + std::to_string(i);
//}

//}

//TEST(DnsCacheStress, twoThreads)
//{
////    std::thread
//}

//TEST(DnsCache, UpdateCheck)
//{
//    using namespace network;
//    DNSCache::create(1);
//    auto & cache{ DNSCache::getInstance() };

//    std::string name = "name";
//    std::string ip = "ip";
//    cache.update(name, ip);
//    EXPECT_EQ(ip, cache.resolve(name));
//    ip = "updatededIp";
//    cache.update(name, ip);
//    EXPECT_EQ(ip, cache.resolve(name));
//}

//TEST(DnsCache, FillCheck)
//{
//    using namespace network;
//    constexpr auto kSize{ 10 };
//    DNSCache cache(kSize);
//    auto & cache{ DNSCache::getInstance() };

//    for (int i = 0; i < kSize; ++i)
//    {
//        cache.update(asName(i), asIp(i));
//    }

//    for (int i = 0; i < kSize; ++i)
//    {
//        EXPECT_EQ(cache.resolve(asName(i)), asIp(i));
//    }
//}

//TEST(DnsCache, OverflowCheck)
//{
//    using namespace network;
//    constexpr auto kSize{ 10 };
//    DNSCache cache(kSize);
//    auto & cache{ DNSCache::getInstance() };

//    auto constexpr kOverflowCount{ 2 * kSize };
//    for (int i = 0; i < kOverflowCount; ++i)
//    {
//        cache.update(asName(i), asIp(i));
//    }

//    for (int i = (kOverflowCount - kSize); i < kOverflowCount; ++i)
//    {
//        EXPECT_EQ(cache.resolve(asName(i)), asIp(i));
//    }
//}
