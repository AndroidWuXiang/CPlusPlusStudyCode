#include "LinkListSingle2.h"

// struct LinkNode 
// {
//     struct LinkNode* next;
// };

struct LList
{
    int size;
    struct LinkNode  header;
};


//初始化
LinkList2 Init_LinkList2()
{
    struct LList* list = malloc(sizeof(struct LList));
    if(NULL == list)
    {
        printf("malloc failed\n");
        return NULL;
    }
    list->size = 0;
	list->header.next = NULL;
    return list;
}

//插入节点
bool Insert_LinkList2(LinkList2 linkList, void* data)
{
        if(NULL == linkList)
    {
        printf("linkList is NULL");
        return false;
    }

    struct LList * mylist = (struct LList *)linkList;//内部先进行类型转换
    struct LinkNode* node = (struct LinkNode*)data;
    node->next = NULL;

    struct LinkNode* current = &mylist->header;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;

    ++mylist->size;

    return true;
}
//遍历
void Foreach_LinkList2(LinkList2 linkList, FOREACH2 foreach)
{
    if(NULL == linkList)
    {
        printf("linkList is NULL\n");
        return;

    }

    struct LList * mylist = (struct LList *)linkList;//内部先进行类型转换

    if(mylist->size == 0)
    {
        printf("linkList size is 0\n");
        return;
    }

    struct LinkNode* current = mylist->header.next;

    printf("mylist->size:%d\n", mylist->size);

     while(current != NULL)
    {
        //printf("foreach --------\n");
        struct LinkNode* pNext = current->next;
        foreach(current);
        current = pNext;
    }
}
//按值删除
bool RemoveByVal_LinkList2(LinkList2 linkList, void* data, COMPARE2 compare)
{
    if(NULL == linkList)
    {
        printf("linkList is NULL");
        return false;
    }

    struct LList * mylist = (struct LList *)linkList;//内部先进行类型转换

    struct LinkNode* prev = &(mylist->header);

    struct LinkNode* current = prev->next;

    while(current != NULL)
    {
        if(compare(current, data) == true)
        {
            prev->next = current->next;
            --mylist->size;
            break;
        }
         prev = current;
         current = current->next;
    }
  
    return true;
}
//按位置删除
bool RemoveByPos_LinkList2(LinkList2 linkList, int pos)
{
    if(NULL == linkList)
    {
        printf("linkList is NULL");
        return false;
    }



    struct LList * mylist = (struct LList *)linkList;//内部先进行类型转换

    if(pos < 1 || pos > mylist->size-1)
    {
        printf("pos is not existed");
        return false;
    }

    struct LinkNode* prev = &mylist->header;

    struct LinkNode* current = prev->next;


    for(int i = 0; i < pos; ++i)
    {
        prev = current;
        current = current->next;
    }

    //struct LinkNode* pDel =  current->next;
    prev->next = current->next;
    --mylist->size;
}
//清空
// void Clear_LinkList(LinkList linkList)
// {
//     printf("Clear_LinkList\n");
//     if(NULL == linkList)
//     {
//         printf("linkList is NULL");
//         return;
//     }

//     struct LList * mylist = (struct LList *)linkList;//内部先进行类型转换

//     if(mylist->size == 0)
//     {
//         printf("linkList size is 0\n");
//         return;
//     }

//     struct LinkNode* current = (&mylist->header)->next;

//     while(current != NULL)
//     {
//         struct LinkNode *pNext = current->next;
//         free(current);

//         current = pNext;
//     }

//     mylist->header.next = NULL;
// 	mylist->size = 0;
// }
//销毁
void Destory_LinkList2(LinkList2 linkList)
{
    printf("Clear_LinkList\n");
    if(NULL == linkList)
    {
        printf("linkList is NULL");
        return;
    }
    struct LList * mylist = (struct LList *)linkList;//内部先进行类型转换
    free(mylist);
    mylist = NULL;
}