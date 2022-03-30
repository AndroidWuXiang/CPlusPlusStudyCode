#include<stdlib.h>
#include<string.h>
#include <stdio.h>

#define MAX 1024

typedef void * Queue;
struct QueueNode 
{
    struct QueueNode* next;
};

Queue initQueue();
void DestoryQueue();
void push(Queue queue, void* data);
void* pop(Queue queue);
int sizeQueue(Queue queue);
