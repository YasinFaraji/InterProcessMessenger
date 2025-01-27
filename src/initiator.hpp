#ifndef INITIATOR_HPP
#define INITIATOR_HPP

#include "common.hpp"

#include <mutex>
#include <atomic>
#include <chrono>
#include <thread>
#include <condition_variable>

class Initiator
{
  public:
    Initiator(std::mutex& mtx, std::condition_variable& cv, int& sharedValue, bool& dataReady, std::atomic<bool>& finished)
        : mtx_(mtx)
        , cv_(cv)
        , sharedValue_(sharedValue)
        , dataReady_(dataReady)
        , finished_(finished)
    {
    }

    void run()
    {
        log("Initiator thread started.");

        for (int count = 1; count <= MAX_COUNT; ++count)
        {
            {
                std::unique_lock<std::mutex> lock(mtx_);
                sharedValue_ = count;
                dataReady_ = true;
                log("Initiator sent: " + std::to_string(sharedValue_));
                cv_.notify_one();
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::unique_lock<std::mutex> lock(mtx_);
            cv_.wait(lock, [this] { return !dataReady_; });
        }

        finished_ = true;
        cv_.notify_one();
        log("Initiator thread finished.");
    }

  private:
    std::mutex& mtx_;
    std::condition_variable& cv_;
    int& sharedValue_;
    bool& dataReady_;
    std::atomic<bool>& finished_;
};

#endif // INITIATOR_HPP
