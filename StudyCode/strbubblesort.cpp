#include <stdlib.h>
#include <iostream>
#include <cstring>

void bubbleSort(char** str, int len) {

    for(int i = 0;i < len; i++) {
        for(int j = 0; j < len-i -1; j++) {
            if(**(str+j) > **(str+j+1)) {
                char* temp = *(str+j);
                *(str+j) = *(str+j+1);
                *(str+j+1) = temp;
            }
        }
    }

}

int main() {
    char* str[] = {"strduent", "new", "tree", "bee", "we", "are"};
    bubbleSort(str, 6);
    for(int i = 0;i < 6; i++) {
        printf("%s\n", str[i]);
    }
    return EXIT_SUCCESS;
}