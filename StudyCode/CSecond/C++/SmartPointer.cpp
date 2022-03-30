/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class shape
{
  public:
       shape() {};
       virtual ~shape() {};
       virtual void printName() {cout<<"Shape"<<endl;};
};

class shapeSon : public shape
{
  public:
        shapeSon() {};
        ~shapeSon() {};
        void printName() {cout<<"shapeSon"<<endl;};
};

class shared_count
{
    public:
      shared_count():count_(1){}
      void add_count()
      {
          ++count_;
      }
      
      long reduce_count()
      {
          return --count_;
      }
      
      long get_count() const
      {
          return count_;
      }
    private:
      long count_;
};

template<typename T>
class SmartPointer
{

    public: 
        template<typename U>
        friend class SmartPointer;
        explicit SmartPointer(T* t = nullptr):m_t(t) 
        {
            cout<<"SmartPointer"<<endl;
            if(m_t)
            {
                 cout<<"SmartPointer shared_count_"<<endl;
                shared_count_ = new shared_count();
            }
        }
        
        ~SmartPointer()
        {
            if( m_t && !shared_count_->reduce_count())
            {
                cout<<"~SmartPointer All"<<endl;
                delete m_t; 
                delete shared_count_;
            }

        }
        template<typename U>
        SmartPointer(SmartPointer<U>& t) noexcept
        {
            cout<<"copy"<<endl;
            m_t = t.m_t;
            m_t->printName();
            if(m_t)
            {
                t.shared_count_->add_count();
                shared_count_ = t.shared_count_;
            }
        }
        
        template<typename U>
        SmartPointer(SmartPointer<U>&& t) noexcept
        {
            cout<<"move copy"<<endl;
            m_t = t.m_t;
            m_t->printName();
            if(m_t)
            {
                shared_count_ = t.shared_count_;
                t.m_t = nullptr;
                //t.shared_count_ = nullptr;
            }
        }
        
        template<typename U>
        SmartPointer(const SmartPointer<U>& other, T* ptr) noexcept
        {
          m_t = ptr;
          if(m_t)
          {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
          }
        }
        
        T* release() noexcept
        {
            cout<<"release"<<endl;
            T* t = m_t;
            m_t = nullptr;
            return t;
        }
        
        long get_count() const noexcept
        {
          if(m_t)
          {
            return shared_count_->get_count();
          }
          else
          {
            cout<<"null"<<endl;
            return 0;
          }
          
        }

        SmartPointer& operator=(SmartPointer t) noexcept
        {
            cout<<"operator="<<endl;
            m_t->printName();
            t.swap(*this);
            // shared_count_->add_count();
            return *this;
        }

        void swap(SmartPointer& t) noexcept
        {
            //using std::swap;
            cout<<"swap"<<endl;
            std::swap(m_t, t.m_t);
            
            std::swap(shared_count_, t.shared_count_);
            
        }
        
        void printT() noexcept
        {
            cout<<m_t<<endl;
        }
        
        T& operator*() const noexcept {return * m_t;};
        T* get() const noexcept {return m_t;};
        T* operator->() const noexcept {return m_t;};
        operator bool() const noexcept {return m_t;}
    private:
        T* m_t;
        shared_count* shared_count_;
};

template<typename T, typename U>
SmartPointer<T> dynamic_pionter_cast(const SmartPointer<U>& other)
{
    cout<<"dynamic_cast"<<endl;
    T* ptr = dynamic_cast<T*>(other.get());
    return SmartPointer<T>(other, ptr);
}

class A
{
    public:
      A(){cout<<"A()"<<endl;};
      A(const A& a) {cout<<"A() copy"<<endl;};
      A& operator=(const A& a){cout<<"A() operator="<<endl;};
};

int main()
{

    SmartPointer<shapeSon> p1(new shapeSon);
    cout<<"---"<<p1.get_count()<<endl;
    SmartPointer<shape> p2;
    cout<<"---"<<p2.get_count()<<endl;
    //此时赋值函数的参数不是引用传递，而是值传递，所以构造参数时，会先调用拷贝构造函数创建临时对象的值，然后调用移动构造将临时对象的值转移到参数上，最后再走到了赋值函数内
    // copy->move->operator=
    p2 = p1;
    cout<<"---"<<p1.get_count()<<endl;
    cout<<"---"<<p2.get_count()<<endl;
    
    SmartPointer<shapeSon> p3 = dynamic_pionter_cast<shapeSon>(p2);
    cout<<"---"<<p1.get_count()<<endl;
    cout<<"---"<<p2.get_count()<<endl;
    cout<<"---"<<p3.get_count()<<endl;
    p1.printT();
    p2.printT();
    //p2 = std::move(p1);

    // A a;
    // A b = a;
    // A c;
    // c = a;
    return 0;
}
