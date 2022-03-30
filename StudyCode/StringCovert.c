#include <stdio.h>
#include <stdlib.h>

void covert(char* c, int start, int end) {

    if(start < 0 || end < 1 || start >= end) {
        printf("do nothing!!!\n");
        return;
    }
    covert(c, start + 1, end -1);

    printf("%c, %c\n", c[start], c[end]);
    char temp = (c)[end];
    c[end] = c[start];
    c[start] = temp;
}

int main() {
    char c[11] = "abcde123456";
    covert(c, 0, 10);
    printf("%s\n", c);

}