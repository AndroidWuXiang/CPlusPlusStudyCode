    #include <iostream>
    #include <thread>
    #include <unistd.h>
    #include "MyException.h"
    using namespace std;

    void func()
    {
        throw MyException("Test Exception error");
    }

    int main() 
    {
        try
        {
            /* code */
            func();
        }
        catch(MyException& e)
        {
            //std::cerr << e.what() << '\n';
            cout<<e.what()<<endl;
        }
        
    }