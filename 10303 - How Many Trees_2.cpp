/*20141102 hanting*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int>,vector<int>);
vector<int> mul(vector<int>,vector<int>);
void output(vector<int>);
int main()
{
    int N;
    vector<int> num[1005];
    num[0].push_back(1);
    num[1].push_back(1);
    num[2].push_back(2);
    int MAX=2;
    while(cin>>N)
    {
        if(N<=MAX) output(num[N]);
        else
        {
            for(++MAX;MAX<=N;MAX++)
            {
                for(int i=0;i<MAX/2;i++)
                {
                    num[MAX]=add(num[MAX],mul(num[i],num[MAX-1-i]));
                }
                num[MAX]=mul(num[MAX],num[2]);
                if(MAX%2)
                {
                    num[MAX]=add(num[MAX],mul(num[MAX/2],num[MAX/2]));
                }
            }
            output(num[--MAX]);
        }
    }
    return 0;
}
vector<int> mul(vector<int> a,vector<int> b)
{
    vector<int> Result(a.size()+b.size());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            Result[i+j]+=a[i]*b[j];
        }
    }
    for(int i=1;i<Result.size();i++)
    {
        Result[i]+=Result[i-1]/1000;
        Result[i-1]%=1000;
    }
    for(int i=Result.size()-1;i>=0;i--)
    {
        if(!Result[i]) Result.pop_back();
        else break;
    }
    return Result;
}
vector<int> add(vector<int> a,vector<int> b)
{
    vector<int> Result;
    int Resize=max(a.size(),b.size());
    a.resize(Resize);
    b.resize(Resize);
    for(int i=0;i<a.size();i++)
    {
        Result.push_back(a[i]+b[i]);
    }
    Result.push_back(0);
    for(int i=1;i<Result.size();i++)
    {
        Result[i]+=Result[i-1]/1000;
        Result[i-1]%=1000;
    }
    if(!Result[Result.size()-1]) Result.pop_back();
    return Result;
}
void output(vector<int> N)
{
    for(int i=N.size()-1;i>=0;i--)
    {
        if(i!=N.size()-1&&N[i]<100) cout<<"0";
        if(i!=N.size()-1&&N[i]<10) cout<<"0";
        cout<<N[i];
    }
    cout<<endl;
}
