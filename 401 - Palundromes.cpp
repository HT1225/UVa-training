/* 20150728
 * hanting
 * UVa 401 - Palundromes
 * C++
 */
#include <iostream>
#include <algorithm>
using namespace std;
string Charactor="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string mirror   ="A   3  HIL JM O   2TUVWXYZ1SE Z  8 ";
string Mirror(string str)
{
    for(int i=0;i<str.size();i++)
    {
        int pos=Charactor.find(str[i]);
        str[i]=mirror[pos];
    }
    return str;
}
int main()
{
    string str;
    while(cin>>str)
    {
        string rstr=str;
        reverse(rstr.begin(),rstr.end());
        bool mirrored=false,palindrome=false;
        if(str==rstr) palindrome=true;
        if(Mirror(str)==rstr) mirrored=true;

        if(palindrome and mirrored)
        {
            cout<<str<<" -- is a mirrored palindrome."<<endl;
        }
        else if(palindrome)
        {
            cout<<str<<" -- is a regular palindrome."<<endl;
        }
        else if(mirrored)
        {
            cout<<str<<" -- is a mirrored string."<<endl;
        }
        else
        {
            cout<<str<<" -- is not a palindrome."<<endl;
        }
        cout<<endl;
    }

    return 0;
}
