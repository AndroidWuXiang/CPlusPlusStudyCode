#include "Queue.h"

struct LQueue
{
    struct QueueNode header;
    struct QueueNode *rear;
    int size;
};

Queue initQueue()
{
    struct LQueue *lQueue = malloc(sizeof(struct LQueue));
    lQueue->header.next = NULL;
    lQueue->size = 0;
    lQueue->rear = &lQueue->header;
    return lQueue;
}
void DestoryQueue(Queue queue)
{
	struct LQueue *q = (struct LQueue *)queue;
	q->header.next = NULL;
	q->rear = NULL;
	q->size = 0;

	free(queue);
	queue = NULL;
}
void push(Queue queue, void* data)
{
	if (NULL == queue)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}
    //每次插入，都插入到尾部的位置，然后更新尾部位置
    struct LQueue *q = (struct LQueue *)queue;
    struct QueueNode *dataNode = (struct QueueNode*)data;
    //插入到尾部的下一个的位置
    q->rear->next = dataNode;
    dataNode->next = NULL;
    //更新尾指针，为插入的最新的节点
    q->rear = dataNode;
    q->size++;
}

void* pop(Queue queue)
{
    if (NULL == queue)
	{
		return NULL;
	}

    struct LQueue *q = (struct LQueue *)queue;
    if(q->size == 0)
    {
        return NULL;
    }
    struct QueueNode *dataNode;
    if(q->size == 1)
    {
        dataNode = q->header.next;
        q->header.next = NULL;
		q->rear = &(q->header);
		q->size--;
        return dataNode;
    }

    dataNode =  q->header.next;
    q->header.next = dataNode->next;
    q->size--;
    return dataNode;
}

int sizeQueue(Queue queue)
{
    if (NULL == queue)
	{
		return 0;
	}

    struct LQueue *q = (struct LQueue *)queue;
    return q->size;
}