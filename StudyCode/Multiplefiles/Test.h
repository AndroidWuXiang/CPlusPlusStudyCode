#ifndef TEST_H
#define TEST_H
#include <stdio.h>
class Test {
    public:
     Test(){
         printf("create\n");
     };
     virtual ~Test() {
         printf("delete\n");
     };
     int add(int a,int b);
};
#endif //end Test_H