/*20150315 hanting*/
#include <iostream>
using namespace std;
class BigNum
{
private:
    long long num[15];
    int digit;

public:
    BigNum():num{0},digit(0){}
    BigNum(int a);
    void digitCount();
    BigNum operator*(BigNum a);
    friend BigNum operator+(BigNum Num,int a);
    friend BigNum operator-(BigNum Num,int a);
    BigNum operator-(BigNum a);
    friend bool operator>(BigNum a,BigNum b);
    friend bool operator==(BigNum a,BigNum b);
    friend BigNum pow(int a,int i);
    friend istream& operator>>(istream& in,BigNum &a);
    friend ostream& operator<<(ostream& out,BigNum a)
    {
        out<<a.num[a.digit-1];
        for(int i=a.digit-2;i>=0;i--)
        {
            out.width(4);
            out.fill('0');
            out<<a.num[i];
        }
        return out;
    }

};
int tower[3];
void hanoi(int n,int from,int temp,int to,BigNum &m)
{
    for(int i=n,j=0;i>=0;i--,j++)
    {
        BigNum t;
        t=pow(2,i)-1;
        if(m>t)
        {
            m=m-(t+1);
            tower[from]-=i+1;
            if(i&1)
            {
                tower[temp]+=i;
                tower[to]++;
                hanoi(i,temp,to,from,m);
            }
            else
            {
                tower[to]+=i;
                tower[temp]++;
                hanoi(i,to,from,temp,m);
            }
            break;
        }
        else if(m==t)
        {
            m=m-(t+1);
            tower[from]-=i;
            if(i&1)
            {
                tower[temp]+=i;
            }
            else
            {
                tower[to]+=i;
            }
            break;
        }
    }
}
int main()
{
    int n;
    BigNum m;
    while(cin>>n>>m && n)
    {
        tower[0]=n;
        for(int i=1;i<3;i++) tower[i]=0;

        hanoi(n,0,1,2,m);

        for(int i=0;i<2;i++)
        {
            cout<<tower[i]<<" ";
        }
        cout<<tower[2]<<endl;
    }
}
BigNum::BigNum(int a)
{
    digit=0;
    for(int i=0;i<15;i++) num[i]=0;
    while(a)
    {
        num[digit++]=a%10000;
        a/=10000;
    }
}
void BigNum::digitCount()
{
    for(int i=14;i>=0;i--)
    {
        if(num[i])
        {
            digit=i+1;
            break;
        }
    }
}
BigNum pow(int a,int i)
{
    BigNum temp;
    while(a)
    {
        temp.num[temp.digit++]+=a%10000;
        a/=10000;
    }
    BigNum ans;
    ans=temp;
    for(int j=0;j<i-1;j++)
    {
        ans=ans*temp;
    }
    return ans;
}
BigNum BigNum::operator*(BigNum a)
{
    BigNum ans;
    for(int i=0;i<digit;i++)
    {
        for(int j=0;j<a.digit;j++)
        {
            ans.num[i+j]+=num[i]*a.num[j];
        }
    }
    for(int i=1;i<15;i++)
    {
        ans.num[i]+=ans.num[i-1]/10000;
        ans.num[i-1]%=10000;
    }
    ans.digitCount();
    return ans;
}
BigNum operator+(BigNum Num,int a)
{
    Num.num[0]+=a;
    for(int i=1;i<15;i++)
    {
        Num.num[i]+=Num.num[i-1]/10000;
        Num.num[i-1]%=10000;
    }
    Num.digitCount();
    return Num;
}
BigNum operator-(BigNum Num,int a)
{
    BigNum ans;
    BigNum temp(a);
    ans=Num-temp;
    return ans;
}
BigNum BigNum::operator-(BigNum a)
{
    BigNum ans;
    for(int i=0;i<15;i++)
    {
        ans.num[i]=num[i]-a.num[i];
    }
    for(int i=0;i<14;i++)
    {
        if(ans.num[i]<0)
        {
            ans.num[i]+=10000;
            ans.num[i+1]--;
        }
    }
    ans.digitCount();
    return ans;
}
bool operator>(BigNum a,BigNum b)
{
    for(int i=14;i>=0;i--)
    {
        if(a.num[i]>b.num[i]) return 1;
        else if(a.num[i]<b.num[i]) return 0;
    }
}
bool operator==(BigNum a,BigNum b)
{
    for(int i=0;i<15;i++)
    {
        if(a.num[i]!=b.num[i]) return 0;
    }
    return 1;
}
istream& operator>>(istream& in,BigNum &a)
{
    BigNum temp;
    a=temp;
    string str;
    in>>str;
    if(str.size()%4!=0)
    for(int i=0;i<str.size()%4;i++)
    {
        str='0'+str;
    }
    for(int i=str.size()-1;i>=0;i-=4)
    {
        a.num[a.digit++]=(str[i]-48) + 10*(str[i-1]-48) + 100*(str[i-2]-48) + 1000*(str[i-3]-48);
    }
    return in;
}
