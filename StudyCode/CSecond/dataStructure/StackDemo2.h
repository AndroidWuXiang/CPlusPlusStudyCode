#include<stdlib.h>
#include<string.h>
#include <stdio.h>

struct LinkNode
{
    struct LinkNode* next; 
};

typedef void * LinkStack;

//初始化
LinkStack Init_LinkStack();
//链表的头作为栈的头，每次入栈就往头后一位插入
//入栈
void Push_LinkStack(LinkStack stack, void *data);
//出栈
void Pop_LinkStack(LinkStack stack);
//获得栈顶元素
void *Top_LinkStack(LinkStack stack);
//获得栈的大小
int Size_LinkStack(LinkStack stack);
//销毁栈
void Destroy_LinkStack(LinkStack stack);