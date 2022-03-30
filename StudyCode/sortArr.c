#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// void selectSocket(void *arr, int elementSize, int len, int (*compare)(void *d1, void *d2)) {
//     char* temp = (char*)malloc(elementSize);
//     for(int i = 0; i < len; i++) {
//         int changeI = i;
//         for(int j = i+1; j < len; j++) {
//             char* pChange =  (char*)arr +changeI*elementSize;
//             char* pJ =  (char*)arr +j*elementSize;
//             if(compare(pChange, pJ)) {
//                 changeI = j;
//             }
//         }

//         if(changeI != i) {
//             char* pI = (char*)arr +i*elementSize;
//             memcpy(temp, pI, elementSize);
//             char* pJ = (char*)arr +changeI*elementSize;
//             memcpy(pI, pJ, elementSize);
//             memcpy(pJ, temp, elementSize);
//         }
//     }
    
//     free(temp);
//     temp = NULL;
// }


void selectSocket(void *arr, int elementSize, int len, int (*compare)(void *d1, void *d2)) {
    char* temp = (char*)malloc(elementSize);
    for(int i = 0; i < len; i++) {
        int changeI = i;
        for(int j = i+1; j < len; j++) {
            char* pChange =  (char*)arr +changeI*elementSize;
            char* pJ =  (char*)arr +j*elementSize;
            if(compare(pChange, pJ)) {
                changeI = j;
            }
        }

        if(changeI != i) {
            char* pI = (char*)arr +i*elementSize;
            memcpy(temp, pI, elementSize);
            char* pJ = (char*)arr +changeI*elementSize;
            memcpy(pI, pJ, elementSize);
            memcpy(pJ, temp, elementSize);
        }
    }
    
    free(temp);
    temp = NULL;
}



int myCompare(void* a, void* b) {
    return *(int*)a <= *(int*)b;

}

int myCompare2(void* a, void* b) {
    return *(double*)a > *(double*)b;

}




int main() {
    // int arr[] = {1, 3, 2, 34, 4, 10};

    // selectSocket(arr, sizeof(int), sizeof(arr) / sizeof(int), myCompare);

    // for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    //     printf("%d\n", arr[i]);
    // }


    double arr[] = {1.2, 3.1, 1.1, 3.4, 4, 1.0};

    selectSocket(arr, sizeof(double), sizeof(arr) / sizeof(double), myCompare2);

    for(int i = 0; i < sizeof(arr) / sizeof(double); i++) {
        printf("%.1f\n", arr[i]);
    }
}