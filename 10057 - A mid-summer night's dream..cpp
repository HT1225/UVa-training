/*20150525 hanting*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        int arr[N];
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+N);
        int A1=arr[(N-1)/2] , A2=arr[(N-1)/2+1];
        int Count=0,possibleA;
        if(N&1)
        {
            for(int i=0;i<N && arr[i]<=A2;i++)
            {
                Count+=(arr[i]==A1);
            }
            possibleA=1;
        }
        else
        {
            for(int i=0;i<N && arr[i]<=A2;i++)
            {
                Count+=(arr[i]==A1||arr[i]==A2);
            }
            possibleA=A2-A1+1;
        }
        cout<<A1<<" "<<Count<<" "<<possibleA<<endl;
    }
    return 0;
}
