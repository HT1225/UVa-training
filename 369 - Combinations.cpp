/*20141107 hanting*/
#include <iostream>
using namespace std;
int prime[30];
int factor[100]={0};
int x=0;
void part1(int num)
{
    for(int i=0;num!=1;i++)
    {
        while(num%prime[i]==0)
        {
            factor[prime[i]]++;
            num/=prime[i];
        }
    }
}
void part2(int num)
{
    for(int i=0;num!=1;i++)
    {
        while(num%prime[i]==0)
        {
            factor[prime[i]]--;
            num/=prime[i];
        }
    }
}
void mul(int* ans,int n)
{
    for(int i=0;i<100;i++)
    {
        ans[i]*=n;
    }
    for(int i=1;i<100;i++)
    {
        ans[i]+=ans[i-1]/10;
        ans[i-1]%=10;
    }
}
void output(int *ans)
{
    int i;
    for(i=99;i>=0;i--)
    {
        if(ans[i]!=0) break;
    }
    for(int j=i;j>=0;j--)
    {
        cout<<ans[j];
    }
}
int main()
{
    int Num[100]={0};
    for(int i=2;i<100;i++)
    {
        if(Num[i]==0)
        {
            prime[x++]=i;
            for(int j=i;j<100;j+=i) Num[j]=1;
        }
    }
    int n,m;
    while(cin>>n>>m && n+m)
    {
        for(int i=0;i<100;i++) factor[i]=0;
        cout<<n<<" things taken "<<m<<" at a time is ";
        int ans[100]={1};
        if(m>n/2) m=n-m;;
        for(int i=2;i<=m;i++)
        {
            part2(i);
        }
        for(int i=n;m--;i--)
        {
            part1(i);
        }
        for(int i=2;i<98;i++)
        {
            while(factor[i]--)
            {
                mul(ans,i);
            }
        }
        output(ans);
        cout<<" exactly."<<endl;
    }
    return 0;
}
