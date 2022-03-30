#include <stdlib.h>
#include <iostream>
//*只与最近的变量名匹配

typedef int int_64;

void test1(int *p) {
    printf("2--%d\n", *p);
    *p = 100;

}

void test2() {
    int p  = 10;
    printf("1--%d\n", p);
    test1(&p);
    printf("3--%d\n", p);
}

int main() 
{
    int_64 a = 100;
    //printf("%d\n",a);

    // for(int i = 0; i<10;++i) 
    // {
    //     printf("%d\n", i);
    // }
    test2();
    return EXIT_SUCCESS;
}