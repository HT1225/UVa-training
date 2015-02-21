/*20150221 hanting*/
#include <iostream>
using namespace std;
struct BigNum
{
    int num[61];
    int digit;
    BigNum()
    {
        fill(num,num+61,0);
        digit=0;
    }
    int digitCount()
    {
        for(int i=60;i>=0;i--)
        {
            if(num[i]!=0) return i+1;
        }
    }
    BigNum operator+(BigNum a)
    {
        BigNum sum;
        for(int i=0;i<61;i++)
        {
            sum.num[i]=num[i]+a.num[i];
        }
        for(int i=1;i<61;i++)
        {
            sum.num[i]+=sum.num[i-1]/1000;
            sum.num[i-1]%=1000;
        }
        int sumDigit=max(digit,a.digit);
        sum.digit=(sum.num[sumDigit] ? sumDigit+1:sumDigit);

        return sum;
    }
    void operator=(int i)
    {
        digit=0;
        while(i)
        {
            num[digit++]=i%1000;
            i/=1000;
        }
    }
    friend ostream& operator<<(ostream& bout,BigNum bnum)
    {
        bout<<bnum.num[bnum.digit-1];
        for(int i=bnum.digit-2;i>=0;i--)
        {
            bout.width(3);
            bout.fill('0');
            bout<<bnum.num[i];
        }
        return bout;
    }
};
void output(BigNum *Last,int lastCount,BigNum *This)
{
    cout<<Last[0];
    for(int i=1;i<lastCount;i++)
    {
        cout<<" "<<Last[i];
    }
    cout<<endl;
    if(Last[lastCount/2].digit>=21) return ;
    int ThisCount=lastCount+1;
    This[0]=1;
    for(int i=1;i<=lastCount/2;i++)
    {
        BigNum temp;
        temp=Last[i]+Last[i-1];
        This[i]=This[lastCount-i]=temp;
    }
    This[lastCount]=1;
    BigNum *Next=Last;
    output(This,ThisCount,Next);
}
int main()
{
    BigNum Last[1000];
    BigNum This[1000];
    Last[0]=1;
    output(Last,1,This);
    return 0;
}
