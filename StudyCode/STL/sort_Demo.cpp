#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> v = {1, 10, 8 , 4, 32, 100, 34, 20, 101};
    std::vector<int>::iterator gogalPosition = v.begin() + v.size()/2;
    //查找区间中间值
    nth_element(v.begin(), gogalPosition, v.end());
    for(auto i : v)
    {
        cout<<i<<endl;
    }

    cout<<"gogalPosition:"<<*gogalPosition<<endl;
    return 0;
}