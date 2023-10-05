#include "ssafy_mining_machine.h"

void status_mining_machine(Queue *queue)
{
    char buf[1000];
    sprintf(buf, "채굴기 개수 : %d\n", queue->size);
    putstr_fd(STDOUT_FILENO, buf);
}