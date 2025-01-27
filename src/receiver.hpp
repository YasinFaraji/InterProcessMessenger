#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include "common.hpp"

#include <mutex>
#include <atomic>
#include <thread>
#include <condition_variable>

class Receiver
{
  public:
    Receiver(std::mutex& mtx, std::condition_variable& cv, int& sharedValue, bool& dataReady, std::atomic<bool>& finished)
        : mtx_(mtx)
        , cv_(cv)
        , sharedValue_(sharedValue)
        , dataReady_(dataReady)
        , finished_(finished)
    {
    }

    void run()
    {
        log("Receiver thread started.");

        while (!finished_)
        {
            std::unique_lock<std::mutex> lock(mtx_);
            cv_.wait(lock, [this] { return dataReady_ || finished_; });

            if (finished_)
                break;

            log("Receiver received: " + std::to_string(sharedValue_));
            sharedValue_ += 1;

            dataReady_ = false;
            cv_.notify_one();
        }

        log("Receiver thread finished.");
    }

  private:
    std::mutex& mtx_;
    std::condition_variable& cv_;
    int& sharedValue_;
    bool& dataReady_;
    std::atomic<bool>& finished_;
};

#endif // RECEIVER_HPP
