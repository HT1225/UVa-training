/*20150223 hanting*/
#include <iostream>
using namespace std;
int f[10001][401]={0};
void output(int *f)
{
    int i=400;
    while(f[i]==0 && i>0) i--;
    cout<<f[i];
    for(int j=i-1;j>=0;j--)
    {
        cout.width(3);
        cout.fill('0');
        cout<<f[j];
    }
    cout<<endl;
}
int main()
{
    f[0][0]=0;
    f[1][0]=1;
    for(int i=2;i<10001;i++)
    {
        //f[i]=f[i-1]+f[i-2]
        for(int j=0;j<400;j++)
        {
            f[i][j]=f[i-1][j]+f[i-2][j];
        }
        for(int j=1;j<400;j++)
        {
            f[i][j]+=f[i][j-1]/1000;
            f[i][j-1]%=1000;
        }
    }
    int N;
    while(cin>>N) output(f[N]);
    return 0;
}
