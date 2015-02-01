/*20150201 hanting*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    long long int N;
    while(cin>>N && N)
    {
        int a[N];
        string s;
        cin.get();
        getline(cin,s);
        stringstream sin(s);
        int positive[N],posNum=0;
        int negative[N],negNum=0;
        for(long long int i=0;i<N;i++)
        {
            sin>>a[i];
            a[i]>0 ? positive[posNum++]=i : negative[negNum++]=i;
        }
        long long int Count=0;
        int temp=0;
        for(int i=0;i<posNum;i++)
        {
            int x=positive[i];
            for(long long int j=temp;j<negNum;j++)
            {
                int y=negative[j];
                if(a[x]>-a[y])
                {
                    Count+=-a[y]*(x>y ? x-y:y-x);
                    a[x]+=a[y];
                    a[y]=0;
                    temp=j;
                }
                else
                {
                    Count+=a[x]*(x>y ? x-y:y-x);
                    a[y]+=a[x];
                    a[x]=0;
                    break;
                }
            }
        }
        cout<<Count<<endl;
    }
    return 0;
}
