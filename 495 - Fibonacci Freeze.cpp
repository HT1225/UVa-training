/*20150223 hanting*/
#include <iostream>
using namespace std;
struct BigNum
{
    int num[1200];
    int digit;
    BigNum()
    {
        fill(num,num+1200,0);
        digit=0;
    }
    int digitCount()
    {
        for(int i=1200;i>=0;i--)
        {
            if(num[i]) return i+1;
        }
    }
    void operator=(int n)
    {
        if(n==0) digit++;
        while(n)
        {
            num[digit++]=n%10;
            n/=10;
        }
    }
    BigNum operator+(BigNum a)
    {
        BigNum sum;
        for(int i=0;i<1200;i++)
        {
            sum.num[i]=num[i]+a.num[i];
        }
        for(int i=1;i<1200;i++)
        {
            sum.num[i]+=sum.num[i-1]/10;
            sum.num[i-1]%=10;
        }
        sum.digit=sum.digitCount();
        return sum;
    }
    friend ostream& operator<<(ostream& bout,BigNum b)
    {
        bout<<b.num[b.digit-1];
        for(int i=b.digit-2;i>=0;i--)
        {
            bout<<b.num[i];
        }
        return bout;
    }
};
BigNum DP[5001];
BigNum f(int N)
{
    if(DP[N].digit) return DP[N];
    else
    {
        DP[N]=f(N-1)+f(N-2);
        return DP[N];
    }
}
int main()
{
    DP[0]=0;
    DP[1]=1;
    for(int i=200;i<=5000;i+=200)
    {
        DP[i]=f(i);
    }
    int N;
    while(cin>>N)
    {
        cout<<"The Fibonacci number for "<<N<<" is "<<f(N)<<endl;
    }
    return 0;
}
