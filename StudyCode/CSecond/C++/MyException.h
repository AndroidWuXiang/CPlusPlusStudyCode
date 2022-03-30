#ifndef MYEXCEPTION_H
#define MYEXCEPTION
#include <string>

class MyException : public std::exception
{
    public:
        MyException(std::string myErrinfo);
        virtual ~MyException();
        virtual const char * what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
    private:
        std::string m_myErrinfo;
}; 

#endif