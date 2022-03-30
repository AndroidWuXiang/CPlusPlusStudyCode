#include <thread>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <list>

#include <mutex>          // std::mutex, std::lock_guard, std::adopt_lock
std::mutex mtxA; 
std::mutex mtxB; 

using namespace std;

vector<int> my_v = {1,2,4};


void myPrint() {
   //std::lock_guard<std::mutex> lck (mtx);
   for(auto num = my_v.begin();num!=my_v.end();++num){
       *num = *num+10;
        printf("%d\n", *num);
   }

    printf("=========================\n");
}

class Message {
    public:
        Message(int id):id(id){};
        int id;
};

class MessageRouter {
    public:
        void send() {
            //std::lock_guard<std::mutex> lck (mtx);
            
            for(int i = 0; i< count; ++i) {
                std::unique_lock<std::mutex> lck (mtx);
                mList.push_back(Message(i));
                printf("send id:%d=======\n", i);
                
                lck.unlock();
                sleep(1);
            }
            
        }

        void read() {
            //std::lock_guard<std::mutex> lck (mtx);
            
            for(int i = 0; i< count; ++i) {
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
                sleep(2);
            }
            

        }
    private:
        int count = 100; 
        std::mutex mtx; 
        list<Message> mList;
};


void myPrintB() {
   std::lock_guard<std::mutex> lck (mtxA);
   sleep(1);
   std::lock_guard<std::mutex> lck2 (mtxB);
   for(auto num = my_v.begin();num!=my_v.end();++num){
       *num = *num+10;
        printf("%d\n", *num);
   }

    printf("=========================\n");
}

void myPrintA() {
   std::lock_guard<std::mutex> lck (mtxA);
   sleep(1);
   std::lock_guard<std::mutex> lck2 (mtxB);
   for(auto num = my_v.begin();num!=my_v.end();++num){
       *num = *num+10;
        printf("%d\n", *num);
   }
    //myPrintB();
    printf("=========================\n");
}





int main() {
    // vector<thread> my_thread;
    // for(int i = 0; i< 10; ++i) {
    //     my_thread.push_back(thread(myPrint));
    // }

    // for(auto thread = my_thread.begin();thread!=my_thread.end();++thread) {
    //     thread->join();
    // }


    // vector<thread> my_thread;
    // shared_ptr<MessageRouter> m_MessageRouter = make_shared<MessageRouter>();
    // thread read = thread(&MessageRouter::read, m_MessageRouter);
    // thread send = thread(&MessageRouter::send, m_MessageRouter);
    
    // read.join();
    // send.join();

    thread A = thread(myPrintA);
    thread B = thread(myPrintB);
    A.join();
    B.join();
    
}