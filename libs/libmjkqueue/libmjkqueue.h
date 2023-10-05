#ifndef LIBMJKQUEUE_H
#define LIBMJKQUEUE_H

#include <stdbool.h>

typedef struct Node
{
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *newQueue();
int sizeQueue(Queue *queue);
bool isEmptyQueue(Queue *queue);
void deleteQueue(Queue *queue);
bool appendQueue(Queue *queue, void *data);
bool insertQueue(Queue *queue, int index, void *data);
bool findQueue(Queue *queue, void *data);
bool removeQueueByIndex(Queue *queue, int index);
bool removeQueueByData(Queue *queue, void *data);
void *peekQueue(Queue *queue);
void *peekQueueByIndex(Queue *queue, int index);
void *popQueue(Queue *queue);
void *popQueueByIndex(Queue *queue, int index);

#endif
