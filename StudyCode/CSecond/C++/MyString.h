#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <cstring>

class MyString
{
    friend std::ostream&  operator<<(std::ostream& cout,MyString& myStr);
    friend std::istream&  operator>>(std::istream& cin, MyString& myStr);
    public:
        MyString(const char* str);
        MyString();
        MyString(const MyString& myStr);
        MyString& operator=(const char* str);
        MyString& operator=(const MyString& myStr);
        ~MyString();
        int size() const;
        char* c_str() const;
    private:
         char* m_str;
         int m_size;
};

#endif