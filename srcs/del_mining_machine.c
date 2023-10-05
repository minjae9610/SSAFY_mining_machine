#include "ssafy_mining_machine.h"

bool del_mining_machine(Queue *queue)
{
    pthread_t *thread = (pthread_t *)peekQueue(queue);
    if (thread == NULL)
        return false;
    int status = pthread_cancel(*thread);
    if (status != 0)
        return false;
    status = pthread_join(*thread, NULL);
    if (status != 0)
        return false;

    popQueue(queue);
    free(thread);

    return true;
}
