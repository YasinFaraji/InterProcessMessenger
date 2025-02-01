#include "shared_memory.h"

#include "common.hpp"

SharedMemory::SharedMemory()
{
    shm_fd = shm_open("/shared_counter", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int));
    data = static_cast<int*>(mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    *data = 0;
}

SharedMemory::~SharedMemory()
{
    munmap(data, sizeof(int));
    close(shm_fd);
    shm_unlink("/shared_counter");
}

void SharedMemory::write(int value)
{
    *data = value;
}

int SharedMemory::read()
{
    return *data;
}
