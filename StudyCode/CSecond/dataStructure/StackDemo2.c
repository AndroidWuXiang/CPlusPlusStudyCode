#include "StackDemo2.h"

struct LinkStack_
{
    struct LinkNode header; 
    int size;
};

//初始化
LinkStack Init_LinkStack()
{
    struct LinkStack_* linkStack = malloc(sizeof(struct LinkStack_));

    if(NULL == linkStack)
    {
        printf("malloc failed\n");
        return NULL;
    }
    linkStack->header.next = NULL;
    linkStack->size = 0;
    return linkStack;
}
//入栈
void Push_LinkStack(LinkStack stack, void *data)
{
    if(NULL == stack)
    {
        printf("NULL == stack\n");
        return;
    }

    if(NULL == data)
    {
        printf("NULL == data\n");
        return; 
    }

    struct LinkStack_* linkStack = (struct LinkStack_*)stack;
    struct LinkNode *node = (struct LinkNode*)data;
    node->next = linkStack->header.next;
    linkStack->header.next = node;
    linkStack->size++;
}
//出栈
void Pop_LinkStack(LinkStack stack)
{
    if(NULL == stack)
    {
        printf("NULL == stack\n");
        return;
    }

    struct LinkStack_* linkStack = (struct LinkStack_*)stack;
    if(0 == linkStack->size)
    {
        printf("0 == size\n");
        return; 
    }


    struct LinkNode* pFirstNode = linkStack->header.next;
    linkStack->header.next = pFirstNode->next;
    pFirstNode = NULL;
    linkStack->size--;
}
//获得栈顶元素
void *Top_LinkStack(LinkStack stack)
{
    if(NULL == stack)
    {
        printf("NULL == stack\n");
        return NULL;
    }

    struct LinkStack_* linkStack = (struct LinkStack_*)stack;
    if(0 == linkStack->size)
    {
        printf("0 == size\n");
        return NULL; 
    }

    return linkStack->header.next;
}
//获得栈的大小
int Size_LinkStack(LinkStack stack)
{
    if(NULL == stack)
    {
        printf("NULL == stack\n");
        return -1;
    }

    struct LinkStack_* linkStack = (struct LinkStack_*)stack;
    return linkStack->size;
}
//销毁栈
void Destroy_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return;
	}

    struct LinkStack_* linkStack = (struct LinkStack_*)stack;
	free(linkStack);
	linkStack = NULL;

}