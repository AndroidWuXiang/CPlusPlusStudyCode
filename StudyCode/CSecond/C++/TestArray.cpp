#include "TestArray.h"
#include <iostream>
TestArray::TestArray()
{
    std::cout<<"TestArray()"<<std::endl;
    mCapacity = 10;
    mBuf = new int[mCapacity];
    mSize = 0;
}

TestArray::~TestArray()
{
    std::cout<<"~TestArray()"<<mBuf[20]<<std::endl;
    mCapacity = 0;
    mSize = 0;
    if(mBuf != nullptr)
    {
        delete[] mBuf;
    }
}
TestArray::TestArray(int capacity)
{
    std::cout<<"TestArray(capacity)"<<std::endl;
    mCapacity = capacity;
    mBuf = new int[mCapacity];
    mSize = 0;
}
TestArray::TestArray(const TestArray& myArray)
{
    std::cout<<"Copy TestArray()"<<std::endl;
    mCapacity = myArray.getCapacity();
    mBuf = new int[mCapacity];
    mSize =  myArray.getSize();
    memcpy(mBuf, myArray.getArray(), myArray.getCapacity()*sizeof(int));
}
TestArray& TestArray::operator=(const TestArray& myArray)
{
    delete[] mBuf;
    std::cout<<"operator="<<std::endl;
    mCapacity = myArray.getCapacity();
    mBuf = new int[mCapacity];
    mSize =  myArray.getSize();
    memcpy(mBuf, myArray.getArray(), myArray.getCapacity()*sizeof(int));
    return *this;
}

int& TestArray::operator[](int index)
{
    if(index >= mSize-1 || index >= mCapacity || index < 0)
    {
        return mBuf[mSize];
    }
    else
    {
        return mBuf[index];   
    }
}

void TestArray::setData(int data)
{
    // if(mCapacity == mSize)
    // {
    //     int * temp = new int[mCapacity*2];
    //     memcpy(temp, mBuf, mCapacity*sizeof(int));
    //     mBuf = temp;
    //     mCapacity = mCapacity*2;
    // }
    // mBuf[mSize] = data;
    // mSize++;
    setData(mSize, data);
}
void TestArray::setData(int index, int data)
{
    if(mCapacity == mSize)
    {
        int * temp = new int[mCapacity*2];
        memcpy(temp, mBuf, mCapacity*sizeof(int));
        mBuf = temp;
        mCapacity = mCapacity*2;
    }

    if(index > mSize-1 || index > mCapacity || index < 0)
    {
         mBuf[mSize] = data;
    }
    else
    {
        for(int i = mSize-1; i > index-1; --i)
        {
            int temp = mBuf[i];
            mBuf[i+1] = temp;
        }
         mBuf[index] = data;
    }
    mSize++;
}

int TestArray::getData(int index) const
{
    if(index > mSize-1 || index > mCapacity || index < 0)
    {
         return mBuf[mSize-1];
    }
    return mBuf[index];
}
int TestArray::getData() const
{
    return mBuf[mSize-1];
}

int TestArray::getSize() const
{
    return mSize;
}
int TestArray::getCapacity() const
{
    return mCapacity;
}

int* TestArray::getArray() const
{
    return mBuf;
}

//前置++
int TestArray::operator++()
{
    return ++mCapacity;
}
//使用占位去区分前置和后置
int TestArray::operator++(int)
{
    return mCapacity++;
}
