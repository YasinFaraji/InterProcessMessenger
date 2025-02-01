#ifndef SYNCHRONIZATION_HPP
#define SYNCHRONIZATION_HPP

#include <pthread.h>

class Synchronization
{
  private:
    pthread_mutex_t mutex;

  public:
    Synchronization();
    ~Synchronization();
    void lock();
    void unlock();
};

#endif