#pragma once
#ifndef LINKLISTSINGLE2_H
#define LINKLISTSINGLE2_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


#ifdef __cplusplus
extern "C"{
#endif

typedef void * LinkList2;//不对外公布链表数据类型
struct LinkNode 
{
    struct LinkNode* next;
};
typedef void (*FOREACH2)(void*);//链表的数据是不固定的，因此数据类型只有用户知道如何输出
typedef bool (*COMPARE2)(void*, void*);//链表的数据是不固定的，因此将比较标准扔给用户处理

//初始化
LinkList2 Init_LinkList2();

//插入节点
bool Insert_LinkList2(LinkList2 linkList, void* data);
//遍历
void Foreach_LinkList2(LinkList2 linkList, FOREACH2 foreach);
//按值删除
bool RemoveByVal_LinkList2(LinkList2 linkList, void* data, COMPARE2 compare);
//按位置删除
bool RemoveByPos_LinkList2(LinkList2 linkList, int pos);
//清空
void Clear_LinkList2(LinkList2 linkList);
//销毁
void Destory_LinkList2(LinkList2 linkList);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif