#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
once_flag init_flag;

#define SINGLETON_CTOR(x) \
     private:\
            x() = default;\
            x(const x&)=delete;\
            x& operator=(const x&)=delete;\
            ~x()=default;

class Test {
    public:
        static std::shared_ptr<Test> getInstance() {
            printf("Test getInstance\n");
            //双检查锁，但由于内存读写reorder不安全(volatile)
            // if(mTest == nullptr) {
            //     std::lock_guard<std::mutex> lck(m_Mutex);
            //     if(mTest == nullptr) {
            //         mTest = std::shared_ptr<Test>(new Test);
            //     }
            // }
            // return mTest;

            //C++11中可以保证static变量时多线程安全的，在底层实现了加锁操作
            static std::shared_ptr<Test> mTest = std::shared_ptr<Test>(new Test, Destory);
            return mTest;

            //使用call_once
            // cout<<"Test getInstance"<<endl;
            // static std::once_flag mOc;
            // std::call_once(mOc, [&] () { mTest = std::shared_ptr<Test>(new Test, Destory);});
            //return mTest;
        }

    private:
        Test(){cout<<"Test 构造函数"<<endl;};
        // Test(const Test& other);
        ~Test() { cout << "单例对象销毁！" << endl; };
        Test(const Test&)=delete;
        Test& operator=(const Test&)=delete;
        //SINGLETON_CTOR(Test);
        std::mutex m_Mutex;
        //static std::shared_ptr<Test> mTest;
        static void Destory(Test *) {
            cout << "在这里销毁单例对象！" << endl;
        }
    
        
// private:
// 	// 定义一个内部类
// 	class CGarbo{
// 	public:
// 		CGarbo(){};
// 		~CGarbo()
// 		{
// 			if (nullptr != mTest)
// 			{
// 				delete &mTest;
// 				mTest = nullptr;
// 			}
// 		}
// 	};
// 	// 定义一个内部类的静态对象
// 	// 当该对象销毁时，顺带就释放myInstance指向的堆区资源
//     static CGarbo m_garbo;
        
};


void init()
{
	cout << "data has inited" << endl;
}
 
void fun()
{
    //不要在函数中声明局部变量的flag，因为每个线程调用的时候，声明的flag是不一样的
	call_once(init_flag, init);
}

//std::shared_ptr<Test> Test::mTest = nullptr;
int main()
{

	thread t1(Test::getInstance);
	thread t2(Test::getInstance);
	t1.join();
	t2.join();
	return 0;
}