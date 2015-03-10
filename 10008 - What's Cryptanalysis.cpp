/*20150310 hanting*/
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<char,int> a,pair<char,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    else return a.second>b.second;
}
int main()
{
    int N;
    cin>>N;
    cin.get();
    string str[N];
    string total="";
    for(int i=0;i<N;i++)
    {
        getline(cin,str[i]);
        for(int j=0;j<str[i].size();j++)
        {
            if(isalpha(str[i][j])) total+=toupper(str[i][j]);
        }
    }
    pair<char,int> letter[26];//< 字母 , 字母出現的次數 >
    for(int i=0;i<26;i++) letter[i].first=i+'A';
    for(int i=0;i<total.size();i++)
    {
        letter[total[i]-'A'].second++;
    }
    sort(letter,letter+26,compare);
    for(int i=0;letter[i].second;i++)//次數是0就停止輸出
    {
        cout<<letter[i].first<<" "<<letter[i].second<<endl;
    }
    return 0;
}
