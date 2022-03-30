#include <stdlib.h>
#include <stdio.h>
int main() {
    //内存地址都是无符号整型的
    printf("%d\n", sizeof(long*));
    //wild pointer
    void* p;
    int a = 100;
    p = &a;
    printf("%d\n", *(int*)p);
    int arr[100] = {0,102,2,0};
    void* p2 = arr;
    printf("%d\n", *((int*)p2+2));
    *((int*)p2+2) = 999;
    printf("%d\n", *((int*)p2+2));

    //二级指针修改const一级指针
    int b = 100;
    int* const p3 = &b;
    int* const* p4 = &p3;
    printf("%d\n", **p4);
    **p4 = 300;
    printf("%d\n", **p4);

    //在C里面，const 变量，可以通过指针进行修改，但是在C++中不可以
   //原因是C++与C的const虽然看上去好像一样，但其实原理是有所不同的
    int c = 90;
    int* const p5 = &c;
    *p5 = 91;

    const int d = 90;
    printf("%d\n",d);
    int* p6 = (int*)&d;
    *p6 = 91;
    printf("%d\n",d);

    //数组名是数组的首地址，为常量

    int a[10] = {0};
    int *p = a;
    // *(p+i) = a[i];
    return EXIT_SUCCESS;
}