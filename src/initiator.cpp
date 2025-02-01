#include "initiator.h"

#include <iostream>
#include <unistd.h>
#include "common.hpp"
#include "shared_memory.h"
#include "synchronization.h"

namespace IPC
{
void runInitiator()
{
    log("Initiator started");
    SharedMemory shm;
    Synchronization sync;

    shm.write(1);
    log("Initial counter set to 1");
    sync.unlock();

    while (true)
    {
        sync.lock();
        int counter = shm.read();
        if (counter >= 10)
            break;
        shm.write(counter + 1);
        log("Initiator incremented counter: " + std::to_string(counter + 1));
        sync.unlock();
        sleep(1);
    }

    log("Initiator finished");
}
} // namespace IPC