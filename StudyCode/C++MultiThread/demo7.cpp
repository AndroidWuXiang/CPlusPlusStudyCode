#include<iostream>
#include<mutex>
#include<thread>
#include <condition_variable>
#include <vector>
#include <list>
#include <future>
#include <unistd.h>
#include <atomic> 
using namespace std;

int myThread2(int a) {
     printf("myThread2 %d\n", this_thread::get_id());
     std::chrono::milliseconds dura(4*1000);
     this_thread::sleep_for(dura);
     return 10;
}

int myThread(int* a) {
    printf("myThread %d\n", this_thread::get_id());
    std::chrono::milliseconds dura(4*1000);
    this_thread::sleep_for(dura);
    // std::future<int> result = std::async(std::launch::deferred, myThread2);
    // printf("myThread2 %d\n", result.getb());
    *a = 166;
    return *a;
}

void myThread3(std::promise<int> &mPromise, int a) {
    printf("myThread3 %d\n", this_thread::get_id());
    a+=100;
    mPromise.set_value(a);
}

void myThread4(std::shared_future<int> &mFUture) {
    printf("myThread4 %d\n", this_thread::get_id());
    printf("myThread4- %d\n", mFUture.get());
    printf("myThread4+ %d\n", mFUture.get());
}

void myThread5(std::atomic_int* a) {
    for(int i = 0; i < 10000000; ++i) {
        (*a)++;
    }
}


int main() {

    // std::thread t1 = std::thread(myThread);
    // t1.join();
    int a = 188;
    int *b = &a;
    //std::future<int> result = std::async(myThread, b);//异步，不会堵塞,但是不会随着主线程的结束而被迫结束，而是转为后台继续执行
    //printf("continue %d\n", *b);
    //printf("%d\n", result.get());//同步，会堵塞，直至返回结果，线程函数的返回值,不能多次调用
    //result.wait();//等待线程返回，并不返回结果
    // printf("continue %d\n", *b);

    // std::packaged_task<int(int*)> task(myThread);//包装函数
    // std::thread t1(std::ref(task), b);
    // t1.join();
    // std::future<int> result = task.get_future();
    // printf("%d\n", result.get());
    printf("main %d\n", this_thread::get_id());
    std::packaged_task<int(int*)> task2([](int* a){
         printf("lambda %d\n", this_thread::get_id());
         return *a = 100;
     });//包装函数
    //task2(b);//在当前线程中被调用
    // std::thread t2(std::ref(task2), b);
    // t2.join();
    // std::future<int> result2 = task2.get_future();
    // printf("%d\n", result2.get());


    // std::promise<int> promise;
    // std::thread t3 = std::thread(myThread3, std::ref(promise), 100);
    // t3.join();
    // //printf("%d\n", promise.get_future().get());
    // std::future<int> future = promise.get_future();
    // //std::shared_future<int> sfuture = std::move(future);
    // std::shared_future<int> sfuture(future.share());
    // std::thread t4 = std::thread(myThread4, std::ref(sfuture));
    // t4.join();
    std::atomic_int c(0);
    std::thread t5 = std::thread(myThread5, &c);
    t5.join();
    std::thread t6 = std::thread(myThread5, &c);
    t6.join();
    //printf("atomic_int %d\n", c);
    cout<<"result:"<<c<<endl;

    std::future<int> t7 =  std::async(myThread2, 3);
    std::chrono::milliseconds dura(0);
    //判断是否创建了新线程
    std::future_status status = t7.wait_for(dura);
    if(status == std::future_status::deferred) {
        printf("this async task is working in this thread, do not create new thread.\n");
    }
    return EXIT_SUCCESS;
}