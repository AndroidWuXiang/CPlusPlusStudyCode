#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <ctime>
#include <algorithm>

using namespace std;

// struct Person
// {
//     std::string name;
//     int number;
// };

std::vector<int> createNumber()
{
    std::vector<int> numberList;
    numberList.reserve(24);
    for (int i = 0; i < 24; i++)
    {
        while(true)
        {
            int number = rand()%25 + 1;
            if(count(numberList.begin(), numberList.end(), number) == 0)
            {
                numberList.push_back(number);
                break;
            }
        }

    }
    return std::move(numberList);
}

// int getScore(int count)
// {
//     std::multiset<int> scoreList;
//     for (int i = 0; i < count; i++)
//     {

//         int number = rand()%100 + 1;
//         scoreList.insert(number);
//     }

//     scoreList.erase(scoreList.begin());
//     scoreList.erase(--scoreList.end());

//     int sum = 0;
//     for(auto score : scoreList)
//     {
//         sum += score;
//     }
//     return sum/(count-2);
// }

// int main()
// {
//     srand((int)time(0));
//     std::vector<int> numberList = createNumber();
//     std::multimap<int, Person> group1;
//     Person p1 = {std::string("周洁"), numberList[0]};
//     group1.insert(make_pair(getScore(10), p1));
//     Person p2 = {std::string("吉冈里帆"), numberList[1]};
//     group1.insert(make_pair(getScore(10), p2));
//     Person p3 = {std::string("马场富美加"), numberList[2]};
//     group1.insert(make_pair(getScore(10), p1));
//     Person p4 = {std::string("新垣结衣"), numberList[4]};
//     group1.insert(make_pair(getScore(10), p4));
//     Person p5 = {std::string("石原里美"), numberList[5]};
//     group1.insert(make_pair(getScore(10), p5));
//     Person p6 = {std::string("北川景子"), numberList[6]};
//     group1.insert(make_pair(getScore(10), p6));
//     cout<<"每一组前三名晋级："<<endl;
//     cout<<"第一组："<<endl;
//     for(auto& person : group1)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }

//     std::map<int, Person> group2;
//     Person p7 = {std::string("周洁2"), numberList[7]};
//     group2.insert(make_pair(getScore(10), p7));
//     Person p8 = {std::string("吉冈里帆2"), numberList[8]};
//     group2.insert(make_pair(getScore(10), p8));
//     Person p9 = {std::string("马场富美加2"), numberList[9]};
//     group2.insert(make_pair(getScore(10), p9));
//     Person p10 = {std::string("新垣结衣2"), numberList[10]};
//     group2.insert(make_pair(getScore(10), p10));
//     Person p11 = {std::string("石原里美2"), numberList[11]};
//     group2.insert(make_pair(getScore(10), p11));
//     Person p12 = {std::string("北川景子2"), numberList[12]};
//     group2.insert(make_pair(getScore(10), p12));
//     cout<<"第二组："<<endl;
//     for(auto& person : group2)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     std::map<int, Person> group3;
//     Person p13 = {std::string("周洁3"), numberList[13]};
//     group3.insert(make_pair(getScore(10), p13));
//     Person p14 = {std::string("吉冈里帆3"), numberList[14]};
//     group3.insert(make_pair(getScore(10), p14));
//     Person p15 = {std::string("马场富美加3"), numberList[15]};
//     group3.insert(make_pair(getScore(10), p15));
//     Person p16 = {std::string("新垣结衣3"), numberList[16]};
//     group3.insert(make_pair(getScore(10), p16));
//     Person p17 = {std::string("石原里美3"), numberList[17]};
//     group3.insert(make_pair(getScore(10), p17));
//     Person p18 = {std::string("北川景子3"), numberList[18]};
//     group3.insert(make_pair(getScore(10), p18));
//     cout<<"第三组："<<endl;
//     for(auto& person : group3)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     std::map<int, Person> group4;
//     Person p19 = {std::string("周洁4"), numberList[19]};
//     group4.insert(make_pair(getScore(10), p19));
//     Person p20 = {std::string("吉冈里帆4"), numberList[20]};
//     group4.insert(make_pair(getScore(10), p20));
//     Person p21 = {std::string("马场富美加4"), numberList[21]};
//     group4.insert(make_pair(getScore(10), p21));
//     Person p22 = {std::string("新垣结衣4"), numberList[22]};
//     group4.insert(make_pair(getScore(10), p22));
//     Person p23 = {std::string("石原里美4"), numberList[23]};
//     group4.insert(make_pair(getScore(10), p23));
//     Person p24 = {std::string("北川景子4"), numberList[24]};
//     group4.insert(make_pair(getScore(10), p24));
//     cout<<"第四组："<<endl;
//     for(auto& person : group4)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }

//     cout<<"--------================"<<endl;
//     for(int i = 0; i < 3; ++i)
//     {
//         group1.erase(--group1.end());

//         group2.erase(--group2.end());

//         group3.erase(--group3.end());

//         group4.erase(--group4.end());

//     }

//     cout<<"第一组晋级："<<endl;
//     for(auto& person : group1)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     cout<<"第二组晋级："<<endl;
//     for(auto& person : group2)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     cout<<"半决赛第一组："<<endl;
//     std::multimap<int, Person> group_Semifinals_1;
//     for(auto& person : group1)
//     {
//         group_Semifinals_1.insert(make_pair(getScore(10), person.second));
//     }

//     for(auto& person : group2)
//     {
//         group_Semifinals_1.insert(make_pair(getScore(10), person.second));
//     }
//     cout<<"第三组晋级："<<endl;
//     for(auto& person : group3)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     cout<<"第四组晋级："<<endl;
//     for(auto& person : group4)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     std::multimap<int, Person> group_Semifinals_2;
//     for(auto& person : group3)
//     {
//         group_Semifinals_2.insert(make_pair(getScore(10), person.second));
//     }

//     for(auto& person : group4)
//     {
//         group_Semifinals_2.insert(make_pair(getScore(10), person.second));
//     }

//     for(int i = 0; i < 3; ++i)
//     {
//         group_Semifinals_1.erase(--group_Semifinals_1.end());

//         group_Semifinals_2.erase(--group_Semifinals_2.end());

//     }
//     cout<<"半决赛第一组晋级："<<endl;
//     for(auto& person : group_Semifinals_1)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     cout<<"半决赛第二组晋级："<<endl;
//     for(auto& person : group_Semifinals_2)
//     {
//         cout<<"姓名："<<person.second.name<<endl;
//         cout<<"编号："<<person.second.number<<endl;
//         cout<<"得分："<<person.first<<endl;
//         cout<<"--------"<<endl;
//     }
//     return EXIT_SUCCESS;

// }

struct Player
{
    std::string name;
    int score[3];
};

void createSpeaker(std::vector<int>& numberList, std::map<int, Player>& playerList)
{
    for (int i = 0; i < 24; i++)
    {    
        while(true)
        {
            int number = rand()%25 + 1;
            if(count(numberList.begin(), numberList.end(), number) == 0)
            {
                Player p;
                std::string name = std::string("Player"+to_string(i));
                p.name = name;
                for (int j = 0; j < 3;j++)
                {
                    p.score[j] = 0;
                }
                numberList.push_back(number);
                playerList.insert(make_pair(number, p));
                break;
            }
        }
    }
}

void shuffle(std::vector<int>& numberList)
{
    random_shuffle(numberList.begin(), numberList.end());
}

int getScore()
{
    std::multiset<int> scoreList;
    for (int i = 0; i < 10; i++)
    {

        int number = rand()%100 + 1;
        scoreList.insert(number);
    }

    scoreList.erase(scoreList.begin());
    scoreList.erase(--scoreList.end());

    int sum = 0;
    for(auto score : scoreList)
    {
        sum += score;
    }
    return sum/(8);
}

void speechContest(int index, std::vector<int>& numberList, std::map<int, Player>& playerList, std::vector<int>& numberList_win)
{
    int count = 0;
    multimap<int, int, greater<int>> groupMap;
    for (auto number : numberList)
    {
        ++count;
        playerList[number].score[index-1] = getScore();
        groupMap.insert(make_pair(playerList[number].score[index-1], number));
        if(count%6 == 0)
        {
            int count_ = 0;
            for(multimap<int, int>::iterator i = groupMap.begin(); i != groupMap.end(),count_ < 3; ++i, ++count_)
            {
                numberList_win.push_back(i->second);
            }
            groupMap.clear();
        }
    }
}

void showWinner(int index, std::map<int, Player> &playerList, std::vector<int>& numberList_win)
{
    cout<<"---------------"<<index<<"----------------"<<endl;
    for (auto number : numberList_win)
    {
        cout<<"number:"<<number<<endl;
        cout<<"name:"<<playerList[number].name<<endl;
        cout<<"The "<<index<<" round's score:"<<playerList[number].score[index-1]<<endl;
        cout<<"---------------"<<endl;
    }
}

int main()
{
    std::vector<int> numberList;
    numberList.reserve(24);
    std::vector<int> numberList_win_1;
    std::vector<int> numberList_win_2;
    std::vector<int> numberList_win_3;
    numberList_win_1.reserve(12);
    numberList_win_2.reserve(6);
    numberList_win_3.reserve(3);
    std::map<int, Player> playerList;
    createSpeaker(numberList, playerList);
    shuffle(numberList);
    speechContest(1, numberList, playerList, numberList_win_1);

    showWinner(1, playerList, numberList_win_1);

    speechContest(2, numberList_win_1, playerList, numberList_win_2);

    showWinner(2, playerList, numberList_win_2);

    speechContest(3, numberList_win_2, playerList, numberList_win_3);

    showWinner(3, playerList, numberList_win_3);

}
