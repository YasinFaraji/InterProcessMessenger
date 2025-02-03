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

void SharedMemory::receiveSharedMemory()
{
    const char* shm_name = "/shared_counter";

    shm_fd = shm_open(shm_name, O_RDWR, 0666);
    if (shm_fd == -1)
    {
        throw std::runtime_error("Failed to open shared memory");
    }

    data = static_cast<int*>(mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (data == MAP_FAILED)
    {
        close(shm_fd);
        throw std::runtime_error("Failed to map shared memory");
    }
}

void SharedMemory::initiateSharedMemory()
{
    const char* shm_name = "/shared_counter";

    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        throw std::runtime_error("Failed to create shared memory");
    }

    if (ftruncate(shm_fd, sizeof(int)) == -1)
    {
        close(shm_fd);
        throw std::runtime_error("Failed to set shared memory size");
    }

    data = static_cast<int*>(mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (data == MAP_FAILED)
    {
        close(shm_fd);
        throw std::runtime_error("Failed to map shared memory");
    }

    *data = 0;
}

void SharedMemory::write(int value)
{
    *data = value;
}

int SharedMemory::read()
{
    return *data;
}
