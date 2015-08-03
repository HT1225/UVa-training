/* 20150731
 * hanting
 * UVa 156 - Ananagrams
 * C++
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>//sort
using namespace std;
int main()
{
    map<string,string> Map;
    string str;
    while(cin>>str and str!="#")
    {
        string SortStr=str;
        transform(SortStr.begin(),SortStr.end(),SortStr.begin(),::tolower);
        sort(SortStr.begin(),SortStr.end());
        if(Map[SortStr].size()) Map[SortStr]="#";
        else Map[SortStr]=str;
    }
    vector<string> vec;
    for(map<string,string>::iterator it=Map.begin();it!=Map.end();++it)
    {
        if((it->second)!="#") vec.push_back(it->second);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0;
}
