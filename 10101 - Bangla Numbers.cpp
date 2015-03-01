/*20150302 hanting*/
#include <iostream>
#include <iomanip>//setw
using namespace std;
int main()
{
    long long N=0;
    int times=0;
    long long numbers[]={1e2,1e3,1e5,1e7,1e9,1e10,1e12,1e14};
    while(cin>>N)//23764//45897458973958
    {
        string Bangla[]={"shata","hajar","lakh","kuti","shata","hajar","lakh","kuti"};
        int x=0;//Bangla[]//numbers[]
        cout<<setw(4)<<++times<<". ";
        int ans[8]={0};
        for(int i=0;i<8;i++)
        {
            if(i<7)ans[i]=N/numbers[i]-N/numbers[i+1]*(numbers[i+1]/numbers[i]);
            else ans[i]=N/numbers[i];
        }
        int i=7;
        bool space=0;
        if(ans[3]==0)
        {
            for(int i=4;i<8;i++)
            {
                if(ans[i])
                {
                    Bangla[i]+=" kuti";
                    break;
                }
            }
        }
        for(;i>=0;i--)
        {
            if(ans[i])
            {
                cout<<ans[i]<<" "<<Bangla[i];
                i--;
                space=1;
                break;
            }
        }
        for(;i>=0;i--)
        {
            if(ans[i]) cout<<" "<<ans[i]<<" "<<Bangla[i];
        }

        if(N%100||N==0) cout<<(space ? " ":"")<<N%100;
        cout<<endl;
    }
    return 0;
}
