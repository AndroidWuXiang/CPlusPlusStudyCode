#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

class A
{
    public:
        void func() throw(std::runtime_error, std::bad_alloc);
};

void A::func() throw(std::runtime_error, std::bad_alloc)
{
    //throw std::runtime_error("Test Exception error");
    throw std::bad_alloc();
    
}

int main() 
{
    printf("main start\n");
    try
    {
        /* code */
        A a;
        a.func();
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        //cout<<e.what()<<endl;
    }
    printf("main end\n");
    
}