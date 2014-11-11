/*20141111 hanting*/
#include <iostream>
using namespace std;
int seventeen[105]={0};
void output(int* a,int p)
{
    for(int i=p-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}
inline bool compare(int *seventeen,int *num)
{
    for(int i=104;i>=0;i--)
    {
        if(num[i]>seventeen[i]) return 0;
        else if(num[i]<seventeen[i]) return 1;
    }
    return 1;
}
bool IsSeventeen(int* num,int p)
{
    if(compare(seventeen,num))
    {
        if((num[0]==7 && num[1]==1)||p==0) return 1;
        else return 0;
    }
    else
    {
        int d=num[0];
        d*=5;
        for(int i=0;i<p-1;i++)//shift ( remove the last number )
        {
            num[i]=num[i+1];
        }

        num[p-1]=0;
        p--;
        int sub_5d[105]={d};
        for(int i=1;i<2;i++)//carry
        {
            sub_5d[i]+=sub_5d[i-1]/10;
            sub_5d[i-1]%=10;
        }
        /*num-5d*/
        int siz=max(p,2);
        for(int i=0;i<siz;i++)
        {
            num[i]-=sub_5d[i];
        }
        for(int i=0;i<siz;i++)
        {
            if(num[i]<0)
            {
                num[i]+=10;
                num[i+1]--;
            }
        }
        if(num[siz]<0)//if( num < 5d )
        {
            num[siz]=0;
            for(int i=0;i<siz;i++)//complement
            {
                num[i]=9-num[i];
            }
            num[0]++;
            for(int i=1;i<siz;i++)//carry
            {
                num[i]+=num[i-1]/10;
                num[i-1]%=10;
            }
        }
        for(int i=104;i>=0;i--)
        {
            if(num[i]!=0)
            {
                p=i+1;
                break;
            }
            else if(i==0) p=0;
        }
        return IsSeventeen(num,p);
    }
}
int main()
{
    seventeen[0]=7;
    seventeen[1]=1;
    string s;
    while(cin>>s && s!="0")
    {
        int num[105]={0};
        int p=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            num[p++]=s[i]-48;
        }
        cout<<IsSeventeen(num,p)<<endl;
    }
    return 0;
}
