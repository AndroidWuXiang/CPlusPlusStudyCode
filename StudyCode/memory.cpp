//声明的时候，不会分配内存空间，定义才会分配内存空间
//extern int a;就是声明
//static 的作用域范围只限于定义文件中，无法使用extern

//代码区：程序指令
//数据区：静态区，全局区，初始化的数据（变量，静态变量）和未初始化的数据，字符串常量
//栈区 变量，数组（只有C语言在栈区，其余语言基本在堆区），结构体，指针等临时变量,向下增长
//堆区 需要手动去回收内存 向上增长
//
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "unistd.h"

int main() {
    // for(;;) {
    //     printf("start\n");
    //     static int a = 10;
    //     printf("%d\n", a++);
    // }

    // auto a = 10;
    int a = 100;
    auto b = "1234";
    printf("%d\n",a);
    printf("%s\n",b);
    
    int* p;
    {
        int a = 1000;
        p = &a;
    }
    int c = 1000;
    //sleep(4);
    printf("p=%d\n", *p);
    int test[1000000] = {0};
    return EXIT_SUCCESS;

}