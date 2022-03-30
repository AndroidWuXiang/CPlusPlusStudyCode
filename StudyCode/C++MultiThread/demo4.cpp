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
//    std::unique_lock<std::mutex> lck (mtxA,std::try_to_lock);
//    if(!lck.owns_lock()) {
//         printf("try to lock failed \n");
//         return;
//    }
std::unique_lock<std::mutex> lck (mtxA,std::defer_lock);
lck.lock();
   std::chrono::milliseconds dura(2000);
   std::this_thread::sleep_for(dura);
   for(auto num = my_v.begin();num!=my_v.end();++num){
       *num = *num+10;
        printf("%d\n", *num);
   }

    printf("=========================\n");
//lck.unlock();
}

void myPrintA() {
   std::unique_lock<std::mutex> lck (mtxA);
   for(auto num = my_v.begin();num!=my_v.end();++num){
       *num = *num+10;
        printf("%d\n", *num);
   }
    //myPrintB();
    printf("=========================\n");
}

void myPrintC() {
   std::unique_lock<std::mutex> lck (mtxA);
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
    sleep(2);
    thread C = thread(myPrintC);
    C.join();
    
}