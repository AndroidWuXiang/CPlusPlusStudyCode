#include <stdlib.h>
#include <iostream>
#include <cstring>

int strstrTest(const char* src, const char* str) {
    int str1 = strlen(src);
    int str2 = strlen(str);
    printf("str:%d\n", str2);
    if(str1 < str2) {
        return -1;
    }
    // printf("src:%c\n", *(src+2));
    int index  = 0;
    while(index < str1) {
        if(*(src + index) == *str) {
            int indexStr = 0;
            while(indexStr < str2) {
                if(*(src+index+indexStr) == *(str+indexStr)) {
                    printf("indexStr:%d\n", indexStr);
                    indexStr++;
                    if(*str+indexStr == '\0'){
                       break;
                    }
                } else if(*(src+index+indexStr) != *(str+indexStr) && *(str+indexStr) == '\0'){
                    printf("success!\n");
                    break;
                } else {
                    printf("indexStr = -1\n");
                    indexStr = -1;
                    break;
                }
            }
            if(indexStr > -1) {
                printf("index\n");
                return index;
            }
        }
        printf("index++\n");
        index++;
    }
    return -1;
}

int main() {
    //常量区
    const char* a = "hello world";
    const char* b = "l";
    printf("%d\n", strstrTest(a,b));

    //栈区
    char a2[] = "tuzicao";
    a2[2] = 'o';
    printf("%s\n", a2);
    return EXIT_SUCCESS;
}