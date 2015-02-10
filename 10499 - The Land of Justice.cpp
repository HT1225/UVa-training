/*20150211 hanting*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n>0)
    {
        if(n==1) cout<<"0%"<<endl;
        else
        {
            double ans=n/4.*100.;
            cout<<fixed<<setprecision(0)<<ans<<"%"<<endl;
        }
    }
    return 0;
}
