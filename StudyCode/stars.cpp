#include <stdlib.h>
#include <iostream>
#include <string.h>

int main() {
     int row = 10;
     for(int i = 0; i < row;i++) {
        // char temp[11];
        // memset(temp, 0, sizeof(temp));
        // for(int j = 0;j<11;j++) {
        //     temp[11/2 - i + j] = '*';
        //     if((i*2-1)< j) {
        //         break;
        //     }
        // }
        // for(int h = 0;h<11;h++) {
        //     printf("%c", temp[h]);
        // }

        int count = 2*i+1;
        for(int j = 0;j<row*2+1;j++) {
            if(count == 0){
                break;
            } else if(j >=(row-1-count/2)) {
                printf("*");
                count--;
            } else{
                printf(" ");
            } 

        }


        // for(int j = 0;j<row -i;j++) {
        //     printf(" ");
        // }

        // for(int h = 0;h<2*i-1; h++) {
        //     printf("*");
        // }
        printf("\n");
    }


    printf("\n");
    return 0;
}