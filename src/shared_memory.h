#ifndef SHARED_MEMORY_HPP
#define SHARED_MEMORY_HPP

#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>

class SharedMemory
{
  private:
    int shm_fd;
    int* data;

  public:
    SharedMemory();
    ~SharedMemory();
    void write(int value);
    int read();
};

#endif