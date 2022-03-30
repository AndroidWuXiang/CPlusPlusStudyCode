#include <stdlib.h>
#include <iostream>

int main() {

    int a[] {10,43,2,5,1,83,54};
    printf("%d\n",sizeof(a));
    for(int i = 0; i<(sizeof(a)/sizeof(int));i++) {
        if(i == (sizeof(a)/sizeof(int))-1) {
           printf("%d\n",a[i]); 
           continue;
        }
        printf("%d,",a[i]);
    }
    //升序
    // for(int i = 0;i < sizeof(a)/sizeof(int);i++) {
    //     for(int j = 0;j <sizeof(a)/sizeof(int)-i;j++) {

    //         if(a[j]>a[j+1] && j!= sizeof(a)/sizeof(int)-i) {
    //             int tmp = a[j];
    //             a[j] = a[j+1];
    //             a[j+1] = tmp;
    //         }
    //     }

    // }
    //降序
    // int exchange = false;
    // for(int i = 0;i < sizeof(a)/sizeof(int);i++) {
    //     int exchange = false;
    //     for(int j = 0;j <sizeof(a)/sizeof(int)-i -1;j++) {

    //         if(a[j]<a[j+1]) {
    //             int tmp = a[j];
    //             a[j] = a[j+1];
    //             a[j+1] = tmp;
    //             exchange = true;
    //         }
    //     }
    //     if(exchange == false){
    //         //若为false，则说明数组中，每个数的位置都是正确的位置，已经完成了排序，减少循环的次数
    //         break;
    //     }

    // }

    //使用指针版本，毫无意义，除了巩固了一下数组与指针的关系
    int length = sizeof(a)/sizeof(int);
    int *p = a;
    for(int i = 0;i < length;i++) {
        int exchange = false;
        for(int j = 0;j < length-i-1;j++) {

            if(a[j]<a[j+1]) {
                int tmp = *(p+j);
                *(p+j) =*(p+j+1);
                *(p+j+1) = tmp;
                exchange = true;
            }
        }
        if(exchange == false){
            //若为false，则说明数组中，每个数的位置都是正确的位置，已经完成了排序，减少循环的次数
            break;
        }
    }
    for(int i = 0; i<(length);i++) {
        if(i == (length)-1) {
           printf("%d",a[i]); 
           continue;
        }
        printf("%d,",a[i]);
    }
    return 0;
}