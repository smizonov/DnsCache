#include <thread>
#include <sstream>
#include <string>
#include <memory>

#include <gtest/gtest.h>

#include <DnsCache.h>
#include <Utils.h>

namespace  {
using namespace network;

void multipleWrite(
        utils::DnsCacheMock & cache,
        size_t itarationCount,
        std::shared_ptr<std::string> threadId)
{
    std::stringstream tmp;
    tmp << std::this_thread::get_id();
    *threadId = tmp.str();
    for (size_t i = 0; i < itarationCount; ++i)
    {
        cache.update(utils::asName(i, *threadId), utils::asIp(i, *threadId));
    }
}

struct ThreadWithId
{
    std::shared_ptr<std::string> id;
    std::unique_ptr<std::thread> t;
};

}

TEST(DnsCacheStress, FinalRecordingCheck)
{
    auto constexpr cacheSize{ 20 };
    auto constexpr iterationCount{ 100'000 };
    auto constexpr threadsCount{ 5 };
    utils::DnsCacheMock cache(cacheSize);

    std::vector<ThreadWithId> pool;
    for (int i = 0; i < threadsCount; ++i)
    {
        ThreadWithId obj;
        obj.id = std::make_shared<std::string>();
        obj.t = std::make_unique<std::thread>(multipleWrite, std::ref(cache), iterationCount, obj.id);
        pool.emplace_back(std::move(obj));
    }

    for (int i = 0; i < threadsCount; ++i)
    {
        pool[i].t->join();
    }

    size_t remainingSuitableRecordingsCount{ 0 };

    for (int lastsIndes = (iterationCount - cacheSize); lastsIndes < iterationCount; ++lastsIndes)
    {
        for (int threadIndex = 0; threadIndex < threadsCount; ++threadIndex)
        {
            if (utils::asIp(lastsIndes, *pool[threadIndex].id) ==
                    cache.resolve(utils::asName(lastsIndes, *pool[threadIndex].id)))
            {
                ++remainingSuitableRecordingsCount;
            }
        }
    }
    EXPECT_EQ(remainingSuitableRecordingsCount, cacheSize);
}
