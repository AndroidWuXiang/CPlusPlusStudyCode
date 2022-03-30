#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "unistd.h"

typedef int a;

//typedef在工作中用的最多的可能就是去定义函数指针
typedef int (*test)(int ,int );

int sum(int x, int y) {
    return x+y;
}

int main() {
    a b = 10230;
    printf("%d\n", b);
    test a = sum;
    printf("%d\n", a(1,2));
    return EXIT_SUCCESS;
}