/* 20150731
 * hanting
 * UVa 10815 - Andy's First Dictionary
 * C++
 */
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<string> Set;
    string str="";
    char ch;
    while(cin.get(ch))
    {
        if(isalpha(ch))//是字母
        {
            str+=tolower(ch);//變小寫
        }
        else if(str.size())
        {
            Set.insert(str);
            str="";
        }
    }
    for(set<string>::iterator itr=Set.begin();itr!=Set.end();++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}
