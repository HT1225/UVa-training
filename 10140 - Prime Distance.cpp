/*20141108 hanting*/
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
bool Num[100000];
int prime[10000];
int x=0;
bool isprime(unsigned int num)
{
    if(num<100000) return Num[num]==0 ? 1:0;
    int s=sqrt(num);//另存s//在for迴圈會慢
    for(int i=0;prime[i]<=s;i++)
    {
        if(num%prime[i]==0) return 0;
    }
    return 1;
}
int main()
{
    for(unsigned int i=2;i<100000;i++) Num[i]=0;
    Num[1]=1;
    for(unsigned int i=2;i<100000;i++)
    {
        if(!Num[i])
        {
            prime[x++]=i;
            for(unsigned int j=i*2;j<100000;j+=i)
            {
                Num[j]=1;
            }
        }
    }
    unsigned int L,U;
    string s;
    while(getline(cin,s))
    {
        stringstream sin(s);
        sin>>L>>U;
        unsigned int l,u;
        for(l=L;!isprime(l);l++);
        L=l;
        for(u=U;!isprime(u);u--);
        U=u;
        if(L>=U) cout<<"There are no adjacent primes."<<endl;
        else
        {
            int clos1=L,clos2=L,dis1=L,dis2=L;
            int temp1=L,temp2=L;
            int mini=U-L+1,maxi=0;
            unsigned int i;
            if(L==2) i=L+1;
            else i=L+2;
            for( i;i<=U;i+=2)
            {//質數一定是6n+1或6n-1，所以+2+4+2+4判斷增加效率
                if(isprime(i))
                {
                    temp1=temp2;
                    temp2=i;
                    if(temp2-temp1<mini)
                    {
                        clos1=temp1;
                        clos2=temp2;
                        mini=clos2-clos1;
                    }
                    if(temp2-temp1>maxi)
                    {
                        dis1=temp1;
                        dis2=temp2;
                        maxi=dis2-dis1;
                    }
                }
                if((i-1)%6==0) i+=2;//+4
            }
            cout<<clos1<<","<<clos2<<" are closest, "<<dis1<<","<<dis2<<" are most distant."<<endl;
        }
    }
    return 0;
}
