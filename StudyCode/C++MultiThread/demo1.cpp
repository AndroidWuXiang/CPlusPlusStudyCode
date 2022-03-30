#include <thread>
#include <unistd.h>

using namespace std;

void myPrint(int count) {
    printf("this is myPrint %d\n", count);
    sleep(2);
}

int main()
{

printf("----------------------\n");
 thread myThread(myPrint, 10);
//  thread myThread2(myPrint, (2));
//  thread myThread3(myPrint,(3));
//  thread myThread4(myPrint,(4));
//  thread myThread5(myPrint, (5));
printf("%d\n", myThread.joinable());
myThread.join();
printf("%d-\n", myThread.joinable()); 
 //myThread.detach();
//lambda
auto myPrint2 = [] (int count){
     printf("this is myPrint2 %d\n", count);
};
thread myThread2(myPrint2, 10);
myThread2.join();
}

