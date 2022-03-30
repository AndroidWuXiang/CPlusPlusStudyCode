#include <iostream>
#include <vector>

int fun1(int, int);

int (*fun1_p)(int, int);

int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

int multiply(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return a/b;
}
int main()
{

std::vector<decltype(fun1)*> v1 {add, subtract, multiply, divide};

for(auto fun : v1)
{
    std::cout<<fun(10, 2)<<std::endl;
}

}