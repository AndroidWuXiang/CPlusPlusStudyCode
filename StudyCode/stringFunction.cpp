#include <stdlib.h>
#include <iostream>
#include <string.h>

int main() {
    char personInfo[] = "name:wuxiang,age:27;";
    char name[100];
    int age = 0;
    sscanf(personInfo, "name:%s,age:%d", name, &age);
    printf("name:%s,age:%d\n",name,age);

    char personInfo2[100];
    char name2[] = "mark";
    int age2 = 26;
    sprintf(personInfo2, "name:%s,age:%d;", name2, age2);
    printf("personInfo2:%s\n", personInfo2);

    char personInfo3[100];
    char format[] = "name:wu%sang,age:%d";
    sprintf(personInfo3, format,  "xi", 17);
    printf("personInfo3:%s\n", personInfo3);

    char email1[] = "wuxiang@gmail.com";
    //破坏原始char数组
    char *p = strtok(email1, "@");
    std::string p2("wuxiang@gmail.com");
    std::string p3 = p2.substr(5,3);
    printf("%s\n", p3.c_str());
    //printf("%s\n", email1);

    char p4[] = "1234@@56wuziang";
    //atol,atof
    int p4_int = atoi(p4);
    printf("%d\n", p4_int);
    return 0;
}