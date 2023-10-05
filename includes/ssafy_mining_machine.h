#ifndef SSAFY_MINING_MACHINE_H
#define SSAFY_MINING_MACHINE_H

#include "libmjkio.h"
#include "libmjkstd.h"
#include "libmjkqueue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define PROMPT "ssafy>> "

typedef enum command
{
    NONVALID,
    SHOW,
    ADD,
    DEL,
    STATUS,
    EXIT,
} command;

command valid_command(const char *cmd);
void show_coin();
bool add_mining_machine(Queue *queue);
bool del_mining_machine(Queue *queue);
void status_mining_machine(Queue *queue);
void *mining();

extern pthread_mutex_t mutex;
extern unsigned long long coin;

#endif
