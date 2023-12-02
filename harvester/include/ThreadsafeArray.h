

#include <mutex>
#include <string>
#include <iostream>
#include <thread>
#include <condition_variable>

#include "json/value.h"

class ThreadsafeArray
{
private:
    mutable std::mutex mut;
    std::condition_variable data_cond;
    int a;
    std::vector<std::string> raw_data;

public:
    // ThreadsafeData();
    void push_back(std::string data){
        std::lock_guard<std::mutex> lk(mut);
        raw_data.push_back(data);
    }

    void print(){
        std::lock_guard<std::mutex> lk(mut);
        for (auto &i : raw_data){
            std::cout << i << std::endl;
        }
    }

    std::vector<std::string> getArray()
    {
        std::lock_guard<std::mutex> lk(mut);
        return raw_data;
    };
};