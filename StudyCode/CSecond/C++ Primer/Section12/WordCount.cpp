#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <thread>
#include <unistd.h>
using namespace std;

class TextQuery
{
    public:
        TextQuery(ifstream& file);
        pair<string, set<int>> query(string word);

    private:
        vector<string> text;
        map<string, set<int>> wordList;
        int lineNumber;
};

TextQuery::TextQuery(ifstream& file):text(10), wordList(), lineNumber(0)
{
    cout<<"TextQuery"<<endl;
    while (getline(file,  text[lineNumber]))
    {
        ++lineNumber;
        cout<<"lineNumber:"<<lineNumber<<endl;
    }
    cout<<"file lines:"<<lineNumber<<endl;
}
// pair<string, set<int>> TextQuery::query(string word)
// {

// }

int main()
{
    cout<<"Start"<<endl;
    ifstream istrm("./Words.txt");
    TextQuery tq(istrm);
    istrm.close();
    shared_ptr<int> i;
    std::string s;
    s.c_str();
    make_shared
    return 0;
}
