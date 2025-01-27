#ifndef THREAD_COORDINATOR_HPP
#define THREAD_COORDINATOR_HPP

#include "initiator.hpp"
#include "receiver.hpp"

#include <atomic>
#include <condition_variable>
#include <mutex>

class ThreadCoordinator
{
  public:
    ThreadCoordinator()
        : sharedValue_(0)
        , dataReady_(false)
        , finished_(false)
    {
    }

    void runInitiator()
    {
        Initiator initiator(mtx_, cv_, sharedValue_, dataReady_, finished_);
        initiator.run();
    }

    void runReceiver()
    {
        Receiver receiver(mtx_, cv_, sharedValue_, dataReady_, finished_);
        receiver.run();
    }

  private:
    int sharedValue_;
    bool dataReady_;
    std::atomic<bool> finished_;
    std::mutex mtx_;
    std::condition_variable cv_;
};

#endif // THREAD_COORDINATOR_HPP
