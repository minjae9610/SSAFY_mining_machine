#include "ssafy_mining_machine.h"

void show_coin()
{
    char buf[1000];
    sprintf(buf, "총 채굴량 : %llu\n", coin);
    putstr_fd(STDOUT_FILENO, buf);
}