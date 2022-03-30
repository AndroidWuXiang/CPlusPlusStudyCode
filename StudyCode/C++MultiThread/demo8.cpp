#include <thread>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <list>

#include <mutex>          // std::mutex, std::lock_guard, std::adopt_lock

#include <windows.h>
std::mutex mtxA; 
std::mutex mtxB; 

std::recursive_mutex mRecursive_mutex;

using namespace std;

#define __WINDOWSJQ__

class Message {
    public:
        Message(int id):id(id){};
        int id;
};

class MessageRouter {
    public:
        MessageRouter(){
            #ifdef __WINDOWSJQ__
                InitializeCriticalSection(&my_winsec);
            #endif
        }
        void send() {
            //std::lock_guard<std::mutex> lck (mtx);
            
            for(int i = 0; i< count; ++i) {
                #ifdef __WINDOWSJQ__
                    //允许两次进入临界区，但是离开的时候也必须是两次
                    EnterCriticalSection(&my_winsec);
                    mList.push_back(Message(i));
                    LeaveCriticalSection(&my_winsec);
                #else
                    std::unique_lock<std::mutex> lck (mtx);
                    mList.push_back(Message(i));
                    lck.unlock();
                #endif
                printf("send id:%d=======\n", i);
                //lck.unlock();
                sleep(1);
            }
            
        }

        void read() {
            //std::lock_guard<std::mutex> lck (mtx);
            
            for(int i = 0; i< count; ++i) {
                #ifdef __WINDOWSJQ__
                    EnterCriticalSection(&my_winsec);
                    if(mList.empty()) {
                        printf("read empty------------- \n");
                        
                        LeaveCriticalSection(&my_winsec);
                        sleep(2);
                        continue;
                    }

                    auto message = mList.front();
                    printf("read id:%d-------\n", message.id);
                    mList.pop_front();
                    
                    LeaveCriticalSection(&my_winsec);
                #else
                    std::unique_lock<std::mutex> lck (mtx);
                    if(mList.empty()) {
                        printf("read empty------------- \n");
                        
                        lck.unlock();
                        sleep(2);
                        continue;
                    }

                    auto message = mList.front();
                    printf("read id:%d-------\n", message.id);
                    mList.pop_front();
                    
                    lck.unlock();
                #endif
                sleep(2);
            }
            

        }
    private:
        int count = 100; 
        std::mutex mtx; 
        list<Message> mList;
        #ifdef __WINDOWSJQ__
          CRITICAL_SECTION my_winsec;//临界区
        #endif
};

void test2() {
    std::unique_lock<std::recursive_mutex> lck (mRecursive_mutex);
    printf("test2-----\n");
    //lck.unlock();
}

void test() {
    std::unique_lock<std::recursive_mutex> lck (mRecursive_mutex);
    printf("test-----\n");
    test2();
    //lck.unlock();
}



int main() {
    // vector<thread> my_thread;
    // shared_ptr<MessageRouter> m_MessageRouter = make_shared<MessageRouter>();
    // thread read = thread(&MessageRouter::read, m_MessageRouter);
    // thread send = thread(&MessageRouter::send, m_MessageRouter);
    
    // read.join();
    // send.join();
    thread t1 = thread(test);
    t1.join();
    printf("-----\n");
}