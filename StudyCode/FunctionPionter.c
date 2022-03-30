#include <stdio.h>

int test1(int a, int b) {

    return a+b;
}

int test2(int a, int b) {

    return a-b;
}

void doLogic(int(*pFunction)(int,int)) {
    printf("----------%d\n", pFunction(100,10));
}

int main() {
    //int(*pFunction)(int,int) = test1;
    int(*pFunction[2])(int,int);
    pFunction[0] = test1;
    pFunction[1] = test2;
    printf("----------%d\n", pFunction[0](100,10));
    printf("----------%d\n", pFunction[1](100,10));
    // doLogic(test1);
    // doLogic(test2);
}