#include "MyException.h"

MyException::MyException(std::string myErrinfo)
{
    m_myErrinfo = myErrinfo;
}
MyException::~MyException()
{

}
const char* MyException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
    return m_myErrinfo.c_str();
}
