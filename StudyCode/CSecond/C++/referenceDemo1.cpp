#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    // int a = 10;
    // int &b = a;
    // b =100;
    // int *h = &b;
    // *h = 101;
    // cout<<b<<endl;

    // int c[10] = {0};
    // int (&d)[10] = c;
    int a = 10;
    int b = 20;
    a = 10086;
    swap(a, b);
    cout<<"--------------"<<a<<endl;
    cout<<"--------------"<<b<<endl;
    int *h = &b;
    int* &p = h;
    cout<<"--------------"<<*p<<endl;
    p = &a;
    cout<<"--------------"<<*p<<endl;
    const int &x = 100;
    int* y = (int*)&x;
    *y = 10001;
    cout<<"--------------"<<*y<<endl;
    return 0;
}
