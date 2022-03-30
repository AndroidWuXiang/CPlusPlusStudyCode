#include <iostream>
#include <unistd.h>
#include <vector>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "time.h"
#define random(x) rand()%(x)
using namespace std;

void myPrint(int value)
{
     cout<<value<<endl; 
}

struct Person
{
    double score;
    std::deque<int> score_list;
};

bool myCompare(Person& p1, Person& p2)
{
    return p1.score > p2.score;
}

void getAverage(std::vector<Person>& students)
{
    for(std::vector<Person>::iterator i = students.begin(); i != students.end(); ++i)
    {
        int total_score = 0;
        for(auto score: i->score_list)
        {
            total_score += score;
        }
        i->score = (total_score / i->score_list.size()*1.0);
    }
}

void printfSore(std::vector<Person>& students)
{
    for(auto student: students)
    {
        printf("score---%0.2f\n", student.score);
    }
}

class PersonCompare
{
public:
    bool operator()(const Person& p1, const Person& p2)
    {
        return p1.score > p2.score;
    }
};


class moveTest
{
    public:
        moveTest(int value) {cout<<"moveTest"<<endl; a = value;}
        //moveTest(moveTest&& m) {cout<<"moveTest move"<<endl; a = m.a;}
        moveTest(const moveTest& m) {cout<<"moveTest copy"<<endl;a = m.a;}
        ~moveTest(){cout<<"~moveTest"<<endl;}
        int a;
};

class PersonCompare2
{
public:
    bool operator()(const moveTest& p1, const moveTest& p2)
    {
        return p1.a < p2.a;
    }
};


moveTest fun1()
{
  printf("--------\n");
  return  moveTest(10);
};

moveTest fun2()
{
  printf("--------\n");
  return  std::move(moveTest(10));
};

int main()
{

    // std::vector<int> v = {10,11,9,13};
    
    // for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    // {
    //     cout<<*i<<endl;
    // }

    // for(auto value : v )
    // {
    //    cout<<value<<endl; 
    // }
    //for_each(v.begin(), v.end(), myPrint);

    // std::vector<int> v2;
    // v2.resize(4);
    // memcpy(&v2[0], &v[0], sizeof(v[0])*4);
    //cout<<v2[0]<<endl; 
    //for_each(v2.begin(), v2.end(), myPrint);

    //std::vector<int> v3 = std::move(v2);
    //for_each(v3.begin(), v3.end(), myPrint);
    // std::vector<int> v3 = {10,11,9,13,15,20,12};
    //v3.reserve(6);
    // v3.assign(v.begin(), v.end());
    // for_each(v3.begin(), v3.end(), myPrint);
    // printf("------------------\n");
    //for_each(v3.rbegin(), v3.rend(), myPrint);
    //cout<<v3.capacity()<<endl;
    // for(std::vector<int>::const_reverse_iterator i = v3.rbegin(); i != v3.rend(); ++i)
    // {
    //     cout<<*i<<endl;
    // }


    // std::string s = "hello";
    // std::string s2 = (s.c_str());
    // std::string s3 = s;
    // const char* c = s.c_str();
    // const char* c2 = s2.c_str();
    // s.size();
    // //s3[0] = 'w';
    // char* p = (char *)s.c_str();//绕过写时复制，但是在vscode上是无效的
    // p[0] = 'T';
    // printf("%p\n", s.c_str());
    // printf("%p\n", s2.c_str());
    // printf("%p\n", s3.c_str());
    // printf("------------------\n", s.c_str());
    // printf("%s\n", s.c_str());
    // printf("%s\n", s2.c_str());
    // printf("%s\n", s3.c_str());

    // std::vector<Person> students;
    // srand((unsigned)time(NULL));
    // for(int i = 0; i < 5; ++i)
    // {
    //     Person p;
    //     std::deque<int> deque_score;
    //     for(int i = 0; i < 10; ++i)
    //     {
    //         deque_score.push_back(random(100));
    //     }
    //     sort(deque_score.begin(), deque_score.end());
    //     p.score_list = deque_score;
    //     students.push_back(p);
    // }
    // //printf("%d\n", students[0].score_list.size());
    // getAverage(students);
    // printfSore(students);

    // sort(students.begin(), students.end(), myCompare);
    // printf("-----------\n");
    // printfSore(students);
    // std::stack<int> s;
    // s.push(10);
    // printf("-----------%d\n",s.size());
    // int a = s.top();
    // s.pop();
    // printf("-----------%d\n",s.size());

    // std::list<Person> l;
    // l.sort([](Person p1, Person p2)->bool{return p1.score > p2.score;});
    // std::set<Person, PersonCompare> m_set;
    // Person p1;
    // m_set.insert(p1);

    // moveTest m1;
    // printf("--------\n");
    // moveTest m2 = std::move(moveTest());
    // sleep(1);
    // printf("--------\n");
    // sleep(1);
    // printf("--------==\n");
    // const int &a = 10;
    // int b = 100;
    // int d = 300;
    // int& c = b;
    // c = 400;
    // //const int &a = 10;
    // printf("--------:%d\n",a);
    // printf("--------:%d\n",b);
    // printf("--------:%d\n",c);

    //int& h = a;
    // std::map<int,int> m;
    // m.insert(make_pair(1,1));
    // pair<int,float> p = make_pair(1,1.1);
    // cout<<p.first<<endl;
    // cout<<p.second<<endl;
    // p.first = 10;
    // p.second = 12.1;
    // cout<<p.first<<endl;
    // cout<<p.second<<endl;

    // pair<int,float> pair1(10, 3.14);
    // pair<int,float> pair2 = make_pair(18,2.1f);
    // //=make_pair(18,2.0);
    // cout << pair1.first << " " << typeid(pair1.second).name() << endl;
    // cout << pair2.first << " " << typeid(pair2.second).name() << endl;
    // pair1.first=10;
    // pair1.second=1.0f;
    // pair2.second=1.1f;
    // cout << pair1.first << " " << typeid(pair1.second).name() << endl;
    // cout << pair2.first << " " << typeid(pair2.second).name() << endl;

    //std::pair<int, moveTest> p(1, moveTest());
    // std::pair<int, moveTest> p2 = std::make_pair(1,  moveTest());

    //std::make_pair(1, 1.1);
    //  cout << std::make_pair(1, 1.1).first << " " << typeid(std::make_pair(1, 1.1).second).name() << endl;

    //  cout<<1.0<<endl;

    moveTest m1(10);
    printf("--------\n");
    moveTest m2 = m1;
    moveTest m3 = fun2();
    // moveTest m4 = m1;

    // std::multimap<int, int> multimap_1;
    // multimap_1.insert(make_pair(10, 11));
    // multimap_1.insert(make_pair(110, 130));
    // multimap_1.insert(make_pair(10, 12));
    // std::multimap<int, int>::iterator  iterator_1 =  multimap_1.find(10);
    // // cout<<iterator_1->second<<endl;
    // // cout<<++iterator_1->second<<endl;

    // for(auto value : multimap_1)
    // {
    //     cout<<value.first<<endl;
    // }

    // std::map<int, moveTest, PersonCompare2> map_1;
    // map_1.insert(make_pair(10, moveTest(100009)));
    // map_1.insert(make_pair(1, moveTest(1)));
    // map_1.insert(make_pair(13, moveTest(12345)));
    // map_1.insert(make_pair(14, moveTest(123)));

    // for(auto value : map_1)
    // {
    //     cout<<value.second.a<<endl;
    // }
    // vector<int> a;
    // find(a.begin(), a.end(), 10);
    return 0;
}