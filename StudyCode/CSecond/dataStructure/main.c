// #include "StackDemo1.h"
// #include "StackDemo2.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Person
{
    /* data */
    int age;
    char sex[100];
    char name[100];
};

// struct Person2
// {
    /* data */
    //不用指针的原因是，指针永远是4个字节，结构体初始化的时候也就只会
    //初始化4个字节，如果结构体内部保存的这个节点是4个字节当然没问题。
    //但如果不是4个字节而是8个或者更多的字节。那么在void*强制转化为节点的时候，
    //就会出现节点访问越界的情况。总结来说就是void*强转为具体类型的指针的时候，
    //是将具体类型大小的地址给从void*强转过来，假设int*,那就是强转4个字节的地址，如果
    //是short就强转两个字节的地址。
    //代码样例
    // struct A
    // {
    //     short b;
    //     short c;
    //     int a;

    // };int main()
    // {
    //     struct A a = {1, 2, 3};
        
    //     int *b = (int*)&a;//Error，强转访问了两个short的内存
    //     short *c = (short*)&a;

    //     printf("%p\n",&(a.a));
    //     printf("%p\n",&(a.b));
    //     printf("%p\n",&(a.c));
    //     printf("int %d\n",*b);
    //     printf("short %d\n",*c);
    //     printf("sizeof int %d\n",sizeof(*b));
    //     printf("sizeof short %d\n",sizeof(*c));
    //     return 0;
    // }

//     struct LinkNode node;
//     int age;
//     char sex[100];
//     char name[100];
// };

struct Person3
{
    struct QueueNode node;
    int age;
    char sex[100];
    char name[100];
};

int main()
{
    // struct Person p1 = {16, "女", "周洁"};
    // struct Person p2 = {17, "女", "王珏"};
    // struct Person p3 = {18, "女", "徐添"};
    // struct Person p4 = {19, "女", "唐尊"};
    // struct Person p5 = {20, "女", "吉冈里帆"};
    // struct Person p6 = {21, "女", "新垣结衣"};

    // SeqStack stack = Init_SeqStack();

    // if(NULL == stack)
    // {
    //     printf("Init_SeqStack failed!!!\n");
    //     return -1;
    // }


    // Push_SeqStack(stack, &p1);
    // Push_SeqStack(stack, &p2);
    // Push_SeqStack(stack, &p3);
    // Push_SeqStack(stack, &p4);
    // Push_SeqStack(stack, &p5);
    // Push_SeqStack(stack, &p6);
    // //获得栈的大小
    // printf("Size_SeqStack(stack):%d\n", Size_SeqStack(stack));
    // //出栈
    // //

    // printf("Size_SeqStack(stack):%d\n", Size_SeqStack(stack));
    // //获得栈顶元素
    
    // for(;;)
    // {
    //     if(Size_SeqStack(stack) == 0)
    //     {
    //         break;
    //     }
    //     struct Person* top = (struct Person*)Top_SeqStack(stack);
    //     printf("age:%d, sex:%s, name:%s\n", top->age, top->sex, top->name);
    //     Pop_SeqStack(stack);
    // }

    // //销毁栈
    // Destroy_SeqStack(stack);

    // printf("Size_SeqStack(stack):%d\n", Size_SeqStack(stack));

    // struct Person3 p1 = {NULL, 16, "女", "周洁"};
    // struct Person2 p2 = {NULL, 17, "女", "王珏"};
    // struct Person2 p3 = {NULL, 18, "女", "徐添"};
    // struct Person2 p4 = {NULL, 19, "女", "唐尊"};
    // struct Person2 p5 = {NULL, 20, "女", "吉冈里帆"};
    // struct Person2 p6 = {NULL, 21, "女", "新垣结衣"};

    // LinkStack stack = Init_LinkStack();
    // printf("Size_LinkStack(stack):%d\n", Size_LinkStack(stack));
    //链表的头作为栈的头，每次入栈就往头后一位插入
    //入栈
    // Push_LinkStack(stack, &p1);
    // Push_LinkStack(stack, &p2);
    // Push_LinkStack(stack, &p3);
    // Push_LinkStack(stack, &p4);
    // Push_LinkStack(stack, &p5);
    // Push_LinkStack(stack, &p6);
    //出栈
    // void Pop_LinkStack(LinkStack stack);
    //获得栈顶元素
    //void *Top_LinkStack(LinkStack stack);
    //printf("Size_LinkStack(stack):%d\n", Size_LinkStack(stack));
    // for(;;)
    // {
    //     if(Size_LinkStack(stack) == 0)
    //     {
    //         break;
    //     }
    //     struct Person2* top = (struct Person2*)Top_LinkStack(stack);
    //     printf("age:%d, sex:%s, name:%s\n", top->age, top->sex, top->name);
    //     Pop_LinkStack(stack);
    // }
    // printf("Size_LinkStack(stack):%d\n", Size_LinkStack(stack));
    // //获得栈的大小
    //int Size_LinkStack(LinkStack stack);
    //销毁栈
    // Destroy_LinkStack(stack);

    struct Person3 p3_1 = {NULL, 16, "女", "周洁"};
    struct Person3 p3_2 = {NULL, 17, "女", "王珏"};
    struct Person3 p3_3 = {NULL, 18, "女", "徐添"};
    struct Person3 p3_4 = {NULL, 19, "女", "唐尊"};
    struct Person3 p3_5 = {NULL, 20, "女", "吉冈里帆"};
    struct Person3 p3_6 = {NULL, 21, "女", "新垣结衣"};

    Queue queue = initQueue();
    push(queue, &p3_1);
    push(queue, &p3_2);
    push(queue, &p3_3);
    push(queue, &p3_4);
    push(queue, &p3_5);
    push(queue, &p3_6);
    while(sizeQueue(queue) > 0)
    {
        struct Person3* tmp = (struct Person3*)pop(queue);
        printf("age:%d, sex:%s, name:%s\n", tmp->age, tmp->sex, tmp->name);
    }

    printf("sizeQueue(queue):%d\n", sizeQueue(queue));
    DestoryQueue();

}