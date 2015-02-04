/*20150204 hanting*/
#include <iostream>
#include <cmath>
using namespace std;
inline bool isPrime(unsigned sum,int *prime)
{
    unsigned Q=sqrt(sum);
    for(unsigned i=0;prime[i]<=Q;i++)
    {
        if(sum%prime[i]==0) return false;
    }
    return true;
}
int main()
{
    bool Num[50000]={false};
    int prime[10000];
    int x=0;
    for(unsigned i=2;i<50000;i++)
    {
        if(!Num[i])
        {
            prime[x++]=i;
            for(unsigned j=i+i;j<50000;j+=i)
            {
                Num[j]=true;
            }
        }
    }
    string str;
    while(getline(cin,str))
    {
        unsigned sum=0;
        unsigned strSize=str.size();
        for(unsigned i=0;i<strSize;i++)
        {
            sum+=(isupper(str[i]) ? str[i]-=38:str[i]-=96);
        }
        cout<<(isPrime(sum,prime) ? "It is a prime word.":"It is not a prime word.")<<endl;
    }
    return 0;
}
