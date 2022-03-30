#include <stdio.h>

struct Test{
    short c;
    char b;
    int a;
};

int main() {
    printf("%d\n", sizeof(struct Test));

}