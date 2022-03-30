    /******************************************************************************

                                Online C++ Compiler.
                Code, Compile, Run and Debug C++ program online.
    Write your code in this editor and press "Run" button to compile and execute it.

    *******************************************************************************/

    #include <iostream>
    #include "NewArray.hpp"
    #include <thread>
    #include <unistd.h>

    using namespace std;
        

    class Base{
    // public:
    //     int _base=1;
    //     void fun(){
    //         cout<<"Base()"<<endl;
    //     }
    public:
        Base() {cout<<"Base()"<<endl;}
        //virtual ~Base() {cout<<"~Base()"<<endl;}
        virtual ~Base() =0;
    };

    Base::~Base() {cout<<"~Base()"<<endl;}

    class A: public Base{
    // public:
    //     //int _base=2;
    };

    class C: public Base{
    // public:
    //     //int _base=3;
    };

    class F: virtual public Base{
    public:
        int _base=3;
    };

    template<class T>
    class D:public Base{
    public:
        D() {cout<<"D()"<<endl;}
        ~D() {cout<<"~D()"<<endl;}
    };

    class D2:public Base{
    public:
        D2() {cout<<"D2()"<<endl;}
        ~D2() {cout<<"~D2()"<<endl;}
    };

    template<class T>
    void my_swap(T& x, T& y) 
    {
        T temp = x;
        x = y;
        y = temp;
    }

    template<class T>
    void selectSort(T* arr, int len) 
    {
        for(int i = 0; i < len; ++i)
        {
            int maxIndex = i;
            for(int j = i; j < len; ++j)
            {
                if(arr[maxIndex] > arr[j])
                {
                    maxIndex = j;
                }
            }

            if(maxIndex != i)
            {
                my_swap(arr[maxIndex], arr[i]);
            }

        }
    }

    template<class T> class Person;
    template<class T> void PrintT(Person<T>& p);

    template<class T>
    class Person
    {
        friend void PrintT<>(Person& p);
        public:
            Person(T t):m_t(t)
            {

            }

            T getT()
            {
                return m_t;
            }
        private:
            T m_t;
    };

    template<class T>
    void PrintT(Person<T> &p)
    {
        cout<<p.getT()<<endl;
    }


    class Person2
    {
        public:
            Person2() {}
            Person2(int t):m_t(t)
            {

            }

            int getT()
            {
                return m_t;
            }
        private:
            int m_t;
    };

    int main(){
        //D d;
        // d.fun();//Base()
        // d.A::fun();//Base()
        // d.C::fun();//Base()
        // cout<<d._base<<endl;//1
        // cout<<d.Base::_base<<endl;//1
        // cout<<d.A::_base<<endl;//2
        // cout<<d.C::_base<<endl;//3
        // cout<<sizeof(Base)<<endl;//1
        // cout<<sizeof(A)<<endl;//1
        // cout<<sizeof(C)<<endl;//1
        // cout<<sizeof(d)<<endl;//1
        // cout<<sizeof(F)<<endl;//1
        // cout<<sizeof(int*)<<endl;//1
        // D *d = new D();
        // delete d;
        // cout<<"--------------------"<<endl;
        // Base *d2 = new D();
        // delete d2;

        // int arr[10] = {10, 12, 0, 3, 6, 8, 14, 16, 1, 10};
        // char arr_c[11] = "mynamewuxi";
        // selectSort(arr_c, 10);
        // for(int i = 0; i < 10; ++i)
        // {
        //     cout<<arr_c[i]<<endl;
        // }

        // cout<<sizeof(D<int>)<<endl;//1
        // cout<<sizeof(D2)<<endl;//1
        // Person<int> p(102220);
        // PrintT(p);

        // NewArray<int> array;

        // for(int i = 0; i < 100; ++i)
        // {
        //     //sleep(1);
        //     array.setData(i);
        // }

        // for(int i = 0; i < 100; ++i)
        // {
        //     cout<<array.getData(i)<<endl;
        // }

        //Person2* p = new Person2[100];
        NewArray<Person2> array;

        for(int i = 0; i < 300; ++i)
        {
            Person2 p(i);
            array.setData(p);
        }

        // for(int i = 0; i < 300; ++i)
        // {
        //     cout<<array.getData(i).getT()<<endl;
        // }

        cout<<array.getData(10000).getT()<<endl;
        cout<<array[10000].getT()<<endl;
        return 0;
    }
