#include <stdlib.h>
#include <iostream>
#include <cstring>

const char* strchrTest(const char* src, char f) {
    const char* p = src;
    if(src == nullptr) {
        return nullptr;
    }
    while(p !=  "\0") {
        if(*p != f) {
            p++;
        } else {
            break;
        }
    }
    return p;
}

bool charReverse(char* src) {
    int length = strlen(src);
    printf("length:%d\n", length);
    if(src == nullptr) {
        return false;
    }
    //method1
    // for(int i = 0;i < length;i++) {
    //     *(result+i) = src[length-i-1]; 
    // }

    //method2
    //采用对称替换的方法，减少了一半的循环，但是与此同时增加了内存空间的消耗
    char* result = src;
    char* rev = &(src[length-1]);
    while(result < rev) {
        char tmp = *result;
        *result = *rev;
        *rev = tmp;
        result++;
        rev--;
    }
    
    printf("p:%s\n",src);
    return true;

    
}

//我讨厌别人用他们的恐惧来警告我，哪怕有些时候是真的。对方或许是善意的，但是我依旧是无法接受的。
//因为我感觉仿佛是被他们控制了一般，这让我时常感到难受，作呕。或许我是错误的，但是我并不想为此
//做出些许改变。我总是活得胆战心惊的，这究竟是从什么时候开始的呢？我无从得知！！！
//我只是想活着而已，但活着本身就时常让我痛苦不堪了。我试着用一些事来转移注意力。
//看些许的书籍，可惜并未能持续下去。做些许锻炼，谢天谢地，这个我坚持下来了，但好似并未给我带来太多的改变。
//是我要求太高了吗，或许吧。我感觉思绪是凌乱不堪的，此刻写下这些不知所谓的文字，或许下一刻就忘记了，但它确确实实的存在过我的脑海之中。


void exchane(int* a,int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

int main() {


    // char p[100] = "hello world";
    // // char f = 'w';
    // // const char* result = strchrTest(p,f);
    // // if(result!=nullptr && *result != '\0') {
    // //     printf("%s\n", result);
    // // } else {
    // //     printf("there is nothing!!!\n");
    // // }
    // printf("there is nothing!!!\n");
    // char* result;
    // //charReverse(p);
    // if(charReverse(p)) {
    //     printf("result:%s\n", p);
    // } else {
    //     printf("there is nothing!!!\n");
    // }
    //char[] 在栈区
    //char* 字符串常量，在常量区，无法修改，生命周期与程序生命周期相同
    int a = 10;
    int b = 20;
    exchane(&a,&b);
    printf("%d, %d\n", a, b);
    return EXIT_SUCCESS;
} 