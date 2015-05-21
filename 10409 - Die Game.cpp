/*20150521 hanting*/
#include <iostream>
using namespace std;
void change(int* arr,int a,int b,int c,int d)//a << b << c << d << a ...
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=arr[c];
    arr[c]=arr[d];
    arr[d]=temp;
}
int main()
{
    int N;
    while(cin>>N && N)
    {
        string cmd[N];
        for(int i=0;i<N;i++)
        {
            cin>>cmd[i];
        }
        int arr[6]={1,2,3,5,4,6};//上北西南東下
        for(int i=0;i<N;i++)
        {
            if(cmd[i]=="north")
            {
                change(arr,0,3,5,1);
            }
            else if(cmd[i]=="south")
            {
                change(arr,0,1,5,3);
            }
            else if(cmd[i]=="east")
            {
                change(arr,0,2,5,4);
            }
            else
            {
                change(arr,0,4,5,2);
            }
        }
        cout<<arr[0]<<endl;
    }
    return 0;
}
