#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "unistd.h"

//结构体，数据类型内存对齐
//union 所有数据成员会共享最大成员的内存，也有内存对齐
//只有最后赋值是准确的，因为前面赋值的，内存可能会被后来者覆盖修改
union test {
    double d;
    float f;
    int i;
    char c;
    char arr[12];//实际内存大小为16，使用arr的内存，但arr需要和double内存对齐
}t;

struct Student {
    char* name;//4
    int age;//4
    short b;// 2 +2补齐
    char* sex;//4
    short b2;//2 +2补齐
    char a;//1 实际大小为20，因为结构体会将最大的数据类型大小作为基准，因此char
           //使用了b2自动补齐的2,4+4+4+4+2+1(1)自动补齐的,但是如果，连续相邻的都是小于基准大小的
          //类型时，自动补齐的，可以共享使用，如果有超过再去补齐，没有超过的话就补齐第一个就够了
          //(结构体的大小一定是基准的倍数)
};
int main() {

    printf("%d\n", sizeof(struct Student));
    //printf("%d\n", sizeof(short));
    struct Student s[10];
    
    return 0;
}