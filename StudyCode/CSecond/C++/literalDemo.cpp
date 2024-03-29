#include <iostream>

using namespace std;

struct length {
    double value;
    enum unit {
        metre,
        kilometre,
        millimetre,
        centimetre,
        inch,
        foot,
        yard,
        mile,
    };
    static constexpr double factors[] =
    {1.0, 1000.0, 1e-3,
     1e-2, 0.0254, 0.3048,
     0.9144, 1609.344};//C++17开始，编译没有问题，之前的版本会提示找不到引用，需要在类外定义
    explicit length(double v, unit u = metre)
    {
        value = v * factors[u];
    }
};
constexpr double length::factors[];

length operator+(length lhs, length rhs)
{
    return length(lhs.value+rhs.value);
}

length operator"" _m(long double v)
{
    return length(v, length::metre);
}

length operator"" _cm(long double v)
{
    return length(v, length::centimetre);
}

int main()
{
    cout<< (1.0_m+10.0_cm).value<<endl;
    return 0;
}