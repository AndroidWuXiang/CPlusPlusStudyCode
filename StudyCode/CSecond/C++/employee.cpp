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
    cout<<"������"<<employee.name<<endl;
    cout<<"�Ա�"<<employee.sex<<endl;
    cout<<"���䣺"<<employee.age<<endl;
    cout<<"-------------"<<endl;
}

int main()
{

    std::multimap<std::string, Employee> company;
    Employee e1 = {std::string("�ܽ�"), std::string("Ů"), 21, std::string("���²�")};
    Employee e2 = {std::string("����ͮ"), std::string("Ů"), 32, std::string("����")};
    Employee e3 = {std::string("��ԫ����"), std::string("Ů"), 19, std::string("���²�")};
    Employee e4 = {std::string("�����﷫"), std::string("Ů"), 21, std::string("������Բ�")};
    Employee e5 = {std::string("����"), std::string("Ů"), 32, std::string("����")};

    company.insert(make_pair(e1.department,e1));
    company.insert(make_pair(e2.department,e2));
    company.insert(make_pair(e3.department,e3));
    company.insert(make_pair(e4.department,e4));
    company.insert(make_pair(e5.department,e5));

    // for(auto department : company)
    // {
    //     cout<<"���ţ�"<<department.first<<endl;
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