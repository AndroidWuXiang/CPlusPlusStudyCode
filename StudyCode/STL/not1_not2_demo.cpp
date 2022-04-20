#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool (*Fun2)(int a);

bool fun(int a)
{
    return a%2==0;
}

std::function<bool(int)> fun_test;

int main()
{

    std::vector<int> v1;
    v1.resize(9);
    int count = 0;
    for(std::vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
    {
        *i = count;
        ++count;
    }
    Fun2 = fun;
    int count_v = std::count_if( v1.begin(), v1.end(), Fun2);
    std::cout<<"count:"<<count_v<<std::endl;
    fun_test = fun;
    count_v = std::count_if( v1.begin(), v1.end(), not1(fun_test));
    std::cout<<"count:"<<count_v<<std::endl;

    return 0;

}