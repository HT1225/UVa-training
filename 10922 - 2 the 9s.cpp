/*20150412 hanting*/
#include <iostream>
#include <sstream>
using namespace std;
int degree;
void recursive(string str)
{
    int sum=0;
    for(int i=0;i<str.size();i++)
    {
        sum+=str[i]-48;
    }
    degree++;
    if(sum<10)
    {
        if(sum==9) cout<<" is a multiple of 9 and has 9-degree "<<degree<<"."<<endl;
        else cout<<" is not a multiple of 9."<<endl;
        return ;
    }
    stringstream sin;
    sin<<sum;
    recursive(sin.str());
}
int main()
{
    string str;
    while(cin>>str && str!="0")
    {
        cout<<str;
        degree=0;
        recursive(str);
    }
    return 0;
}
