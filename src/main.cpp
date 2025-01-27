#include "thread_coordinator.hpp"

int main()
{
    log("Main process started.");

    ThreadCoordinator coordinator;

    std::thread initiatorThread(&ThreadCoordinator::runInitiator, &coordinator);
    std::thread receiverThread(&ThreadCoordinator::runReceiver, &coordinator);

    initiatorThread.join();
    receiverThread.join();

    log("Main process finished.");
    return 0;
}
