#include <stdlib.h>
#include <stdio.h>
int main() {
        

    int c = 90;
    int* p5 = &c;
    *p5 = 91;
    printf("%d\n", *p5);
    return 0;
}