/*20140826 hanting*/
#include <iostream>
using namespace std;
string temp;
inline string intrstr(string s,int start,int End)
{
    int temp=End-start+1;
    return s.substr(start,End-start+1);
}
int palindrome(string s,int left,int right)
{
    int sum=0;
    while(1)
    {
        if(s[left]==s[right] && left>=0 && right<s.size())
        {
            if(temp.find(s.substr(left,right-left+1))>temp.size())
            {
                temp+=s.substr(left,right-left+1);
                temp+=" ";
                sum++;
            }
            left--;
            right++;
        }
        else return sum;
    }
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        temp.clear();
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans+=palindrome(s,i,i);
            if(s[i]==s[i+1])ans+=palindrome(s,i,i+1);
        }
        cout<<"The string '"<<s<<"' contains "<<ans<<" palindromes."<<endl;
    }
    return 0;
}
