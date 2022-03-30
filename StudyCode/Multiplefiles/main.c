#include <stdio.h>

struct A
{
    short b;
    short c;
    int a;

};

int main()
{
    struct A a = {1, 2, 3};
    
    int *b = (int*)&a;
    short *c = (short*)&a;

    printf("%p\n",&(a.a));
    printf("%p\n",&(a.b));
    printf("%p\n",&(a.c));
    printf("int %d\n",*b);
    printf("short %d\n",*c);
    printf("sizeof int %d\n",sizeof(*b));
    printf("sizeof short %d\n",sizeof(*c));
    return 0;
}