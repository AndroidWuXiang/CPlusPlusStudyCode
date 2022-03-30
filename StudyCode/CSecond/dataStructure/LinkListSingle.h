#pragma once
#ifndef LINKLISTSINGLE_H
#define LINKLISTSINGLE_H

#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<stdio.h>


#ifdef __cplusplus
extern "C"{
#endif
typedef void * LinkList;//不对外公布链表数据类型
typedef void (*FOREACH)(void*);//链表的数据是不固定的，因此数据类型只有用户知道如何输出
typedef bool (*COMPARE)(void*, void*);//链表的数据是不固定的，因此将比较标准扔给用户处理

//初始化
LinkList Init_LinkList();

//插入节点
bool Insert_LinkList(LinkList linkList, void* data);
//遍历
void Foreach_LinkList(LinkList linkList, FOREACH foreach);
//按值删除
bool RemoveByVal_LinkList(LinkList linkList, void* data, COMPARE compare);
//按位置删除
bool RemoveByPos_LinkList(LinkList linkList, int pos);
//清空
void Clear_LinkList(LinkList linkList);
//销毁
void Destory_LinkList(LinkList linkList);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif //LINKLISTSINGLE_H