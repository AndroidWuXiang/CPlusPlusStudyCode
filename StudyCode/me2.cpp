#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "unistd.h"

int main() {
    printf("0000000\n");
    int *p = (int*)malloc(1024*1024*1000);

    while(1);
    return EXIT_SUCCESS;
}