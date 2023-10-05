#include "ssafy_mining_machine.h"

void *mining()
{
    while (true)
    {
        pthread_mutex_lock(&mutex);
        coin += 1;
        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
    return NULL;
}