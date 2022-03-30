#include "MyString.h"

std::ostream&  operator<<(std::ostream& cout,MyString& myStr)
{
    cout<<myStr.c_str();
    return cout;
}

std::istream&  operator>>(std::istream& cin, MyString& myStr)
{
    std::cout<<"operator>>"<<std::endl;
    if(myStr.m_str != nullptr)
    {
        delete myStr.m_str;
        myStr.m_str = nullptr;
    }
    char buf[1024];
    cin>>buf;
    myStr.m_size = strlen(buf);
    myStr.m_str = new char[myStr.m_size + 1];
    return cin;
}


MyString::MyString()
{
    m_size = 0;
}

MyString::MyString(const char* str)
{
    std::cout<<"MyString(const char* str)"<<std::endl;
    m_size = strlen(str);
    m_str = new char[m_size + 1];
    strcpy(m_str, str);
}
MyString::MyString(const MyString& myStr)
{
    std::cout<<"MyString"<<std::endl;
    m_size = myStr.size();
    m_str = new char[m_size + 1];
    strcpy(m_str, myStr.c_str());   
}
MyString::~MyString()
{
    if(m_str != nullptr)
    {
        delete[] m_str;
        m_size = 0;
    }
}

MyString& MyString::operator=(const char* str)
{
    std::cout<<"operator=(const char* str)"<<std::endl;
    m_size = strlen(str);
    m_str = new char[m_size + 1];
    strcpy(m_str, str);
    return *this;
}

MyString& MyString::operator=(const MyString& myStr)
{
    std::cout<<"operator="<<std::endl;
    m_size = myStr.size();
    m_str = new char[m_size + 1];
    strcpy(m_str, myStr.c_str());
    return *this;
}
int MyString::size() const
{
    return m_size;
}
char* MyString::c_str() const
{
    return m_str;
}