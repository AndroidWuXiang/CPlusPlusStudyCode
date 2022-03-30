#include <thread>
#include <unistd.h>
#include <iostream>

using namespace std;

class A {
    public:
        int m_a;
        A(const A & a):m_a(a.m_a){
            cout<<"拷贝构造函数；"<<this<<":"<<std::this_thread::get_id()<<endl;
        };

        A(int a):m_a(a){
            
            cout<<"类型转换函数；"<<this<<":"<<std::this_thread::get_id()<<endl;
        };

};

void myPrint(const A& a) {
    cout<<"myPrint"<<":"<<std::this_thread::get_id()<<endl;
}

int main()
{

printf("----------------------\n");
cout<<"main"<<":"<<std::this_thread::get_id()<<endl;
thread myThread(myPrint, A(10));

//myThread.join();
}

