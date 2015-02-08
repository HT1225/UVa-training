/*20150208 hanting*/
#include <iostream>
#include <algorithm>
using namespace std;
struct DNA
{
    int order;
    int time;
};
int sortingTime(string str)
{
    int time=0;
    for(int i=0;i<str.size();i++)
    {
        for(int j=i+1;j<str.size();j++)
        {
            if(str[i]>str[j]) time++;
        }
    }
    return time;
}
bool compare(DNA a,DNA b)
{
    if(a.time==b.time) return a.order<b.order;
    else return a.time<b.time;
}
int main()
{
    int N;
    int blank=0;
    cin>>N;
    while(N--)
    {
        if(blank) cout<<endl;
        int row,col;
        cin>>col>>row;
        string str[row];
        cin.get();
        for(int i=0;i<row;i++)
        {
            getline(cin,str[i]);
        }
        DNA srt[row];
        for(int i=0;i<row;i++)
        {
            srt[i].order=i;
            srt[i].time=sortingTime(str[i]);
        }
        sort(srt,srt+row,compare);
        for(int i=0;i<row;i++)
        {
            cout<<str[ srt[i].order ]<<endl;
        }
        blank=1;
    }
    return 0;
}
