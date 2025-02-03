#include "receiver.h"

#include <iostream>
#include <unistd.h>
#include "common.hpp"
#include "shared_memory.h"
#include "synchronization.h"

namespace IPC
{
void runReceiver()
{
    log("Receiver started");
    SharedMemory shm(IPC::Mode::Receiver);
    Synchronization sync;

    while (true)
    {
        sync.lock();
        int counter = shm.read();
        if (counter >= 10)
            break;
        shm.write(counter + 1);
        log("Receiver incremented counter: " + std::to_string(counter + 1));
        sync.unlock();
        sleep(1);
    }

    log("Receiver finished");
}
} // namespace IPC
