#include <stdlib.h>
#include <iostream>

int main() {
    for(int i = 1;i<10;i++) {
        for(int j = 1;j<=i; j++) {
            if(j> 1) printf(" ");
            printf("%d*%d = %d", j, i, i*j);
        }
        printf("\n");
    }
    return 0;
}