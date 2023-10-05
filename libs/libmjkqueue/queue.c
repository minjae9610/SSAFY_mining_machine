#include "libmjkqueue.h"

#include <stdbool.h>
#include <stdlib.h>

Queue *newQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
        return NULL;
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int sizeQueue(Queue *queue)
{
    return queue->size;
}

bool isEmptyQueue(Queue *queue)
{
    return queue->size == 0;
}

void deleteQueue(Queue *queue)
{
    while (queue->size > 0)
    {
        void *data = popQueue(queue);
        free(data);
    }
    free(queue);
}

bool appendQueue(Queue *queue, void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
        return false;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (queue->size == 0)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        node->prev = queue->rear;
        queue->rear = node;
    }
    queue->size++;
    return true;
}

bool insertQueue(Queue *queue, int index, void *data)
{
    if (queue->size == 0 || index >= queue->size)
        return false;
    Node *node = queue->front;
    for (int i = 0; i < index; i++)
        node = node->next;
    if (node == NULL)
        return false;
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return false;
    new_node->data = data;
    new_node->prev = node->prev;
    new_node->next = node;
    if (node->prev != NULL)
        node->prev->next = new_node;
    node->prev = new_node;
    if (node == queue->front)
        queue->front = new_node;
    queue->size++;
    return true;
}

bool findQueue(Queue *queue, void *data)
{
    if (queue->size == 0)
        return false;
    Node *node = queue->front;
    while (node != NULL)
    {
        if (node->data == data)
            return true;
        node = node->next;
    }
    return false;
}

bool removeQueueByIndex(Queue *queue, int index)
{
    if (queue->size == 0 || index >= queue->size)
        return false;
    Node *node = queue->front;
    for (int i = 0; i < index; i++)
        node = node->next;
    if (node == NULL)
        return false;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node == queue->front)
        queue->front = node->next;
    if (node == queue->rear)
        queue->rear = node->prev;
    free(node);
    queue->size--;
    return true;
}

bool removeQueueByData(Queue *queue, void *data)
{
    if (queue->size == 0)
        return false;
    Node *node = queue->front;
    while (node != NULL)
    {
        if (node->data == data)
        {
            if (node->prev != NULL)
                node->prev->next = node->next;
            if (node->next != NULL)
                node->next->prev = node->prev;
            if (node == queue->front)
                queue->front = node->next;
            if (node == queue->rear)
                queue->rear = node->prev;
            free(node);
            queue->size--;
            return true;
        }
        node = node->next;
    }
    return false;
}

void *peekQueue(Queue *queue)
{
    if (queue->size == 0)
        return NULL;
    return queue->front->data;
}

void *peekQueueByIndex(Queue *queue, int index)
{
    if (queue->size == 0 || index >= queue->size)
        return NULL;
    Node *node = queue->front;
    for (int i = 0; i < index; i++)
        node = node->next;
    if (node == NULL)
        return NULL;
    return node->data;
}

void *popQueue(Queue *queue)
{
    if (queue->size == 0)
        return NULL;
    Node *node = queue->front;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node == queue->front)
        queue->front = node->next;
    if (node == queue->rear)
        queue->rear = node->prev;
    void *data = node->data;
    free(node);
    queue->size--;
    return data;
}

void *popQueueByIndex(Queue *queue, int index)
{
    if (queue->size == 0 || index >= queue->size)
        return NULL;
    Node *node = queue->front;
    for (int i = 0; i < index; i++)
        node = node->next;
    if (node == NULL)
        return NULL;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node == queue->front)
        queue->front = node->next;
    if (node == queue->rear)
        queue->rear = node->prev;
    void *data = node->data;
    free(node);
    return data;
}
