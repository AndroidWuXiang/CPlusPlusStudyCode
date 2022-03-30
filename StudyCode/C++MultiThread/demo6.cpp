#include<iostream>
#include<mutex>
#include<thread>
#include <condition_variable>
#include <vector>
#include <list>
#include <unistd.h>
using namespace std;




// void myPrint() {
//    std::unique_lock<std::mutex> lck (mtx);

//     cond.wait(lck, [this] {
//         return true;
//     });
//     printf("=========================\n");
// }
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
                mCond.notify_one();
                lck.unlock();
                sleep(1);
            }
            
        }

        void read() {
            //std::lock_guard<std::mutex> lck (mtx);
            
            while (true)
            {
                std::unique_lock<std::mutex> lck (mtx);
                std::chrono::milliseconds dura(2000);
                mCond.wait_for(lck, dura);
                mCond.wait(lck, [this] {
                    printf("-------------wait \n");
                    if(mList.empty()) {
                        printf("read empty-------------wait \n");
                        return false;
                    }
                    return true;//wait会进行解锁
                });
                auto message = mList.front();
                printf("read id:%d-------\n", message.id);
                mList.pop_front();
                lck.unlock();
                sleep(1);
            }

            

        }
    private:
        int count = 1; 
        std::mutex mtx; 
        list<Message> mList;
        std::condition_variable mCond;
};





int main() {

    vector<thread> my_thread;
    shared_ptr<MessageRouter> m_MessageRouter = make_shared<MessageRouter>();
    
    thread send = thread(&MessageRouter::send, m_MessageRouter);
    send.join();
    sleep(1);
    

    thread read = thread(&MessageRouter::read, m_MessageRouter);
    read.join();
}