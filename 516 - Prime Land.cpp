/*20141122 hanting*/
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s) && s!="0")
    {
        stringstream sin(s);
        int sum=1;
        int _pow;
        int num;
        while(sin>>num>>_pow) sum*=pow(num,_pow);
        sum--;
        bool Num[50000]={0};
        int prime[10000];
        int x=0;
        for(int i=2;i<50000;i++)
        {
            if(Num[i]==0)
            {
                prime[x++]=i;
                for(int j=i*2;j<50000;j+=i)
                {
                    Num[j]=1;
                }
            }
        }
        int ans[1000];
        int q=0;
        for(int i=0;sum!=1;i++)
        {
            while(sum%prime[i]==0)
            {
                ans[q++]=prime[i];
                sum/=prime[i];
            }
        }
        for(int i=q-1;i>=0;i--)
        {
            int pow=1;
            if(i!=q-1) cout<<" ";
            cout<<ans[i];
            while(i-1>=0 && ans[i-1]==ans[i])
            {
                pow++;
                i--;
            }
            cout<<" "<<pow;
        }
        cout<<endl;
    }
}
