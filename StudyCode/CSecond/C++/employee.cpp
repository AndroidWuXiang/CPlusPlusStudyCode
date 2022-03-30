#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <deque>
#include <queue>


using namespace std;

struct Employee
{
    std::string name;
    std::string sex;
    int age;
    std::string department;

};

void printEmployeeInfo(const Employee& employee)
{
    cout<<"姓名："<<employee.name<<endl;
    cout<<"性别："<<employee.sex<<endl;
    cout<<"年龄："<<employee.age<<endl;
    cout<<"-------------"<<endl;
}

int main()
{

    std::multimap<std::string, Employee> company;
    Employee e1 = {std::string("周洁"), std::string("女"), 21, std::string("人事部")};
    Employee e2 = {std::string("王欣彤"), std::string("女"), 32, std::string("财务部")};
    Employee e3 = {std::string("新垣结衣"), std::string("女"), 19, std::string("人事部")};
    Employee e4 = {std::string("吉冈里帆"), std::string("女"), 21, std::string("软件测试部")};
    Employee e5 = {std::string("波瑠"), std::string("女"), 32, std::string("财务部")};

    company.insert(make_pair(e1.department,e1));
    company.insert(make_pair(e2.department,e2));
    company.insert(make_pair(e3.department,e3));
    company.insert(make_pair(e4.department,e4));
    company.insert(make_pair(e5.department,e5));

    // for(auto department : company)
    // {
    //     cout<<"部门："<<department.first<<endl;
    //     printEmployeeInfo(department.second);
    // }

    // std::vector<int> v = {1,2,4,3,6,7,8};
    // cout<<v[3]<<endl;

    std::deque<int> d = {1, 100, 2};
    cout<<d.at(1)<<endl;
    std::queue<int> q;
    q.push(10);
    q.push(9);
    q.push(4);
    cout<<<<endl;
}