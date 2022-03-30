// #include "TestArray.h"
#include <iostream>
#include "MyString.h"
using namespace std;

class A
{
    public:
        static A& getInstance()
        {
            if(m_a == nullptr)
            {
                m_a = new A();
            }
            return *m_a;
            //不需要垃圾回收类,但是不能保证原子性了
            // static A a(100);
            // return a;
        }
        ~A()
        {
            printf("~A()\n");
        }
        class Garbage
        {
            public:
                //Garbage() {};
                ~Garbage()
                {
                    if(m_a != nullptr)
                    {
                        printf("~Garbage()\n");
                        delete m_a;
                        m_a = nullptr;
                    }

                }
        };
    private:
        A() {printf("A()\n");}
        explicit A(int a) {printf("A()\n");}
        A(const A& a) =delete;
    private:
        static A* m_a;
        //static Garbage garbage;
};

A* A::m_a = nullptr;
//A::Garbage A::garbage;

// ostream&  operator<<(ostream& cout,TestArray& myArray)
// {
//     cout<<myArray.getCapacity();
//     return cout;
// }

template<typename T>
class SmartPointer
{
    public:
        
        SmartPointer(T *t)
        {
            m_t = t;
        }

        T& operator*()
        {
            return *m_t;
        }

        T& get()
        {
            return *m_t;
        }

        T* operator->()
        {
            return m_t;
        }
        
        ~SmartPointer()
        {
            if(m_t != nullptr)
            {
                delete m_t;
                m_t = nullptr;
            }
        }
    private:
        T* m_t;
};

class Father
{
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

class Son:private Father
{
    // void test() { cout<<b<<endl;}
};


int main()
{
    // TestArray* a = new TestArray(100);
    // TestArray& t = *a;
    //cout<<*a<<endl;

    // printf("t.getCapacity():%d\n", (t++));
    // printf("t.getCapacity():%d\n", (++t));
    // int size = t.getCapacity();
    // for(int i = 0; i < 100; ++i)
    // {
    //     t.setData(i);
    // }
    // t.setData(20, 10024);
    // TestArray t2;
    // t2 = t;//operator=
    // t.setData(20, 100204);
    // printf("t2.getData(20):%d\n", t2.getData(20));
    // printf("t2[20]:%d\n", t2[20]);
    // t2[20] = 520;
    // printf("t2[20]:%d\n", t2[20]);
    // delete a;
    // //SmartPointer<TestArray> mSmartPointer(a);// = new SmartPointer<TestArray>;
    // //printf("mSmartPointer.getCapacity():%d\n", ((mSmartPointer)->getCapacity()));
    // //mSmartPointer
    // SmartPointer<TestArray>* mSmartPointer2 = new SmartPointer<TestArray>(a);
    // printf("mSmartPointer2.getCapacity():%d\n", ((mSmartPointer2->get()).getCapacity()));

    // delete mSmartPointer2;
    // cout<<"getCapacity:"<<t.getCapacity()<<endl;
    // cout<<"getSize:"<<t.getSize()<<endl;
    // t.setData(20, 10024);
    // cout<<"getData(20):"<<t.getData(20)<<endl;
    // TestArray t2;
    // t2 = t;//operator=
    // t2.setData(20, 10028);
    // cout<<"getData(20):"<<t2.getData(20)<<endl;
    // TestArray t3 = t2;//Copy
    // cout<<"getData(20):"<<t3.getData(20)<<endl;
    // delete a;

    // A::getInstance();
    // A* a1;
    // a1 = &(A::getInstance());
    // A::getInstance();
    // MyString myString = "hello my dream";
    // MyString myString2;
    // myString2 = myString;
    // myString2 = "hello my dream - 1024";
    // cout<<myString<<endl;
    // cout<<myString.size()<<endl;
    // cout<<myString.c_str()<<endl;
    // cout<<myString2<<endl;
    // MyString myString;
    // cin>>myString;
    //pause();
    cout<<sizeof(Son)<<endl;
    //system("pause");
}