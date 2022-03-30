/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

class A
{
  private:
      const int a;
};

struct C
{
   C(int i) : i(i) {cout<<"struct C"<<endl;} //< constructor needed (until C++20)
   int i;
};
 
int main()
{
    auto sp = std::make_shared<C>(12);
    auto sp2 = std::make_shared<int>();
    static_assert(std::is_same_v<decltype(sp), std::shared_ptr<C>>);
    
    C c = 10;
 
    std::cout << sp->i << '\n';
}
