#include "synchronization.h"

#include "common.hpp"

Synchronization::Synchronization()
{
    pthread_mutex_init(&mutex, nullptr);
}

Synchronization::~Synchronization()
{
    pthread_mutex_destroy(&mutex);
}

void Synchronization::lock()
{
    pthread_mutex_lock(&mutex);
}

void Synchronization::unlock()
{
    pthread_mutex_unlock(&mutex);
}
