/*20140813 hanting*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
string h="0123456789ABCDEF";
string itoa(long long N,int base)
{
    char s[1000];
    int a[1000];
    int i=0;
    while(N>=base)
    {
        a[i++]=N%base;
        N/=base;
    }
    a[i]=N;
    for(int j=0;j<=i;j++)
    {
        s[j]=h[a[i-j]];
    }
    s[++i]=0;
    string str=s;
    return str;
}
long long strtoDec(char* N,int base)
{
    long long a=0;
    for(int i=0;i<strlen(N);i++)
    {
        int temp=h.find(N[strlen(N)-1-i]);
        a+=temp*pow((double)base,i);
    }
    return a;
}
int main()
{
    int base1,base2;
    char N[1000];
    while(cin>>base1>>base2>>N)
    {
        int Continue=0;
        for(int i=0;i<strlen(N);i++)
        {
            if(h.find(N[i])>=base1)
            {
                Continue=1;
                cout<<N<<" is an illegal base "<<base1<<" number"<<endl;
                break;
            }
        }
        if(Continue) continue;
        long long int N_in_Base10;
        N_in_Base10=strtoDec(N,base1);///strtol只能用int範圍
        cout<<N<<" base "<<base1<<" = "<<itoa(N_in_Base10,base2)<<" base "<<base2<<endl;
    }
    return 0;
}
