#ifndef NEW_ARRAY_H
#define NEW_ARRAY_H
#include <iostream>


template<class T>
class NewArray {
    public:
        NewArray()
        {
            std::cout<<"NewArray()"<<std::endl;
            mCapacity = 100;
            mBuf = new T[mCapacity];
            mSize = 0;
        }

        ~NewArray()
        {
            std::cout<<"~NewArray()"<<std::endl;
            mCapacity = 0;
            mSize = 0;
            if(mBuf != nullptr)
            {
                delete[] mBuf;
            }
        }

        explicit NewArray(int capacity)
        {
            std::cout<<"NewArray(capacity)"<<std::endl;
            mCapacity = capacity;
            mBuf = new T[mCapacity];
            mSize = 0;
        }

        NewArray(const NewArray& myArray)
        {
            std::cout<<"Copy TestArray()"<<std::endl;
            mCapacity = myArray.getCapacity();
            mBuf = new T[mCapacity];
            mSize =  myArray.getSize();
            memcpy(mBuf, myArray.getArray(), myArray.getCapacity()*sizeof(T));
        }

        NewArray& operator=(const NewArray& myArray)
        {
            delete[] mBuf;
            std::cout<<"operator="<<std::endl;
            mCapacity = myArray.getCapacity();
            mBuf = new T[mCapacity];
            mSize =  myArray.getSize();
            memcpy(mBuf, myArray.getArray(), myArray.getCapacity()*sizeof(T));
            return *this;   
        }

        T& operator[](int index)
        {
            if(index > mSize-1 || index >= mCapacity || index < 0)
            {
                return mBuf[mSize-1];
            }
            else
            {
                return mBuf[index];   
            }
        }

        void setData(T data)
        {
            setData(mSize, data);
        }
        
        void setData(int index, T data)
        {
            if(mCapacity == mSize)
            {
                T * temp = new T[mCapacity*2];
                memcpy(temp, mBuf, mCapacity*sizeof(T));
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
                    T temp = mBuf[i];
                    mBuf[i+1] = temp;
                }
                mBuf[index] = data;
            }
            mSize++;
        }

        T getData(int index) const
        {
            if(index > mSize-1 || index >= mCapacity || index < 0)
            {
                return mBuf[mSize-1];
            }
            return mBuf[index];
        }

        T getData() const
        {
            return mBuf[mSize-1];
        }

        int getSize() const
        {
            return mSize;
        }
        int getCapacity() const
        {
            return mCapacity;
        }

        T* getArray() const
        {
            return mBuf;
        }

        //前置++
        int operator++()
        {
            return ++mCapacity;
        }
        //使用占位去区分前置和后置
        int operator++(int)
        {
            return mCapacity++;
        }

    private:
        int mSize;
        int mCapacity;
        T* mBuf;
};

#endif