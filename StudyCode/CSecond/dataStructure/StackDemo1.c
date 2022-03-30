#include "StackDemo1.h"

//顺序栈数据结构
struct SStack
{
    void *data[MAX]; //存放数据的数组
    int size;//栈中元素的个数
};

//初始化
SeqStack Init_SeqStack()
{
    struct SStack* sStack = malloc(sizeof(struct SStack));

    if(NULL == sStack)
    {
        printf("Init_SeqStack failed!!!\n");
        return NULL;
    }

    memset(sStack, 0, sizeof(struct SStack));
    sStack->size = 0;

    return sStack;
}

//入栈
void Push_SeqStack(SeqStack stack, void *data)
{
    if(NULL == stack || NULL == data)
    {
        printf("stack or data is NULL!!!\n");
        return;
    }

    struct SStack* sStack = (struct SStack*)stack;
    sStack->data[sStack->size++] = data;
}

//出栈
void Pop_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        printf("stack is NULL!!!\n");
        return;
    }

    struct SStack* sStack = (struct SStack*)stack;
    if(0 == sStack->size)
    {
        printf("size is 0!!!\n");
        return;
    }
    sStack->data[sStack->size-1] = NULL;
    --sStack->size;
}

//获得栈顶元素
void *Top_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        printf("stack is NULL!!!\n");
        return NULL;
    }
    struct SStack* sStack = (struct SStack*)stack;
    if(0 == sStack->size)
    {
        printf("size is 0!!!\n");
        return NULL;
    }

    return sStack->data[sStack->size-1];
}

//获得栈的大小
int Size_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        printf("stack is NULL!!!\n");
        return 0;
    }
    struct SStack* sStack = (struct SStack*)stack;
    return sStack->size;

}

//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        printf("stack is NULL!!!\n");
        return;
    }

    free(stack);
}