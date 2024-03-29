#include<stdlib.h>
#include<string.h>
#include <stdio.h>

#define MAX 1024

typedef void * SeqStack;

//数组高下标的位置当做栈顶，因为不需要移动数组中的元素在插入和删除中

//初始化
SeqStack Init_SeqStack();
//入栈
void Push_SeqStack(SeqStack stack, void *data);
//出栈
void Pop_SeqStack(SeqStack stack);
//获得栈顶元素
void *Top_SeqStack(SeqStack stack);
//获得栈的大小
int Size_SeqStack(SeqStack stack);
//销毁栈
void Destroy_SeqStack(SeqStack stack);