#include "ssafy_mining_machine.h"

bool add_mining_machine(Queue *queue)
{
    pthread_t *thread = malloc(sizeof(pthread_t));
    if (thread == NULL)
        return false;
    int status = pthread_create(thread, NULL, mining, NULL);
    if (status != 0)
        return false;

    appendQueue(queue, thread);

    return true;
}