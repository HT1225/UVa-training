/*20150523 hanting*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    int times=1;
    while(cin>>N)
    {
        bool B2=true;
        bool Num[20002]={false};
        int arr[N];
        int temp;
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
            if(arr[i]<1) B2=false;
            else if(i!=0 && arr[i]<=temp) B2=false;
            temp=arr[i];
        }
        for(int i=0;i<N && B2;i++)
        {
            for(int j=i;j<N && B2;j++)
            {
                int sum=arr[i]+arr[j];
                if(Num[sum]==false) Num[sum]=true;
                else B2=false;
            }
        }
        cout<<"Case #"<<times++<<": ";
        if(B2) cout<<"It is a B2-Sequence."<<endl;
        else cout<<"It is not a B2-Sequence."<<endl;
        cout<<endl;
    }
    return 0;
}
