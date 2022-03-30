#include <stdlib.h>
#include <iostream>

int main() {
// for(int i = 0; i < 100;i++) {
//     //0-10's random number
//     printf("%d\n", rand()%11);
// }

for(int i = 0; i < 100;i++) {
    //0-33's random number
    //0-any's random number :rand()%any + 1
    printf("%d\n", rand()%33+1);
}
return 0;
}