#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H
#include<cstring>

class TestArray {
    public:
        TestArray();
        ~TestArray();
        explicit TestArray(int capacity);
        TestArray(const TestArray& myArray);
        TestArray& operator=(const TestArray& myArray);
        int& operator[](int index);
        void setData(int data);
        void setData(int index, int data);
        int getData(int index) const;
        int getData() const;
        int getSize() const;
        int getCapacity() const;
        int* getArray() const;
        //前置++
        int operator++();
        //使用占位去区分前置和后置
        int operator++(int);

    private:
        int mSize;
        int mCapacity;
        int* mBuf;
// };
#endif