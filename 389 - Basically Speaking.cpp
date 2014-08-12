/*20140812 hanting*/
#include <iostream>
#include <cstdlib>
#include<cstring>
#include <vector>
#include <iomanip>
using namespace std;
void itoa(int base,int a,char *s)
{
    vector<int> temp;
    char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(a>=base)
    {
        temp.push_back(a%base);
        a/=base;
    }
    temp.push_back(a);
    int Size=temp.size();
    for(int i=0;i<Size;i++)
    {
        s[i]=hex[temp.back()];
        temp.pop_back();
    }
    s[Size]=0;
}
int main()
{
    char s[100];
    while(cin>>s)
    {
        int fromBase,toBase;
        cin>>fromBase>>toBase;
        int from;
        from=strtol(s,NULL,fromBase);
        itoa(toBase,from,s);
        if(strlen(s)<=7)
            cout<<setw(7)<<s<<endl;
        else
            cout<<setw(7)<<"ERROR"<<endl;
    }
    return 0;
}
