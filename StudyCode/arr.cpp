#include <stdlib.h>
#include <iostream>
int main() {
    int a[10] = {9,3,4,6,1,0,8,7,2,10};
        for(int i = 0; i<(sizeof(a)/sizeof(int));i++) {
        if(i == (sizeof(a)/sizeof(int))-1) {
           printf("%d\n",a[i]); 
           printf("-------------\n"); 
           continue;
        }
        printf("%d,",a[i]);
    }
    for(int i = 0; i<(sizeof(a)/sizeof(int))/2;i++) {
        int tmp = a[i];
        a[i] = a[sizeof(a)/sizeof(int)-i-1];
        a[sizeof(a)/sizeof(int)-i-1] = tmp;
    }
    for(int i = 0; i<(sizeof(a)/sizeof(int));i++) {
        if(i == (sizeof(a)/sizeof(int))-1) {
           printf("%d",a[i]); 
           continue;
        }
        printf("%d,",a[i]);
    }
    return 0;
}