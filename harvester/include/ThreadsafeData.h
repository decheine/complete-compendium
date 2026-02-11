

#include <mutex>
#include <string>
#include <thread>
#include <condition_variable>

#include <json/value.h>

class ThreadsafeData
{
private:
    mutable std::mutex mut;
    std::condition_variable data_cond;
    int a;
    Json::Value raw_monsterData;

public:
    // ThreadsafeData();
    void AddMonster(std::string monsterName, Json::Value monsterJson)
    {
        std::lock_guard<std::mutex> lk(mut);
        raw_monsterData[monsterName] = monsterJson;
        data_cond.notify_all();
    };

    Json::Value GetJson()
    {
        std::lock_guard<std::mutex> lk(mut);
        return raw_monsterData;
    };

    int size()
    {
        std::lock_guard<std::mutex> lk(mut);
        return raw_monsterData.size();
    };
};