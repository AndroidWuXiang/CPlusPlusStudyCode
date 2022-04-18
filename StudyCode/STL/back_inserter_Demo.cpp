/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> v1;
    v1.resize(10);
    int count = 0;
    for(std::vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
    {
        *i = count;
        ++count;
    }

    // for(auto i : v1)
    // {
    //     cout<<i<<endl;
    // }
    std::vector<int> v2;
    // v2.resize(v1.size(), 1000);
    // v2.reserve(v1.size()+v2.size());
    std::transform(v1.begin(), v1.end(), std::back_insert_iterator<std::vector<int>>(v2), [=](int x) {return x*10;});

    cout<<v2.size()<<endl;
    for(auto i : v2)
    {
        cout<<i<<" ";
    }
    cout<<"----------------"<<endl;
    // std::transform(v1.rbegin(), v1.rend(), v2.begin(), [=](int x) {return x*100;});
    // for(auto i : v2)
    // {
    //     cout<<i<<endl;
    // }


    return 0;
}
