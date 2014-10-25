/*20141023 hanting*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> stage(int);
vector<int> mul(vector<int>,vector<int>);
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<n<<"!"<<endl;
        if(!n)
        {
            cout<<1<<endl;
            continue;
        }
        vector<int> output=stage(n);
        for(int i=output.size()-1;i>=0;i--)
        {
            if(output[i]<10 && i!=output.size()-1) cout<<"00";
            else if(output[i]<100 && i!=output.size()-1) cout<<"0";
            cout<<output[i];
        }cout<<endl;
    }
    return 0;
}
vector<int> stage(int num)
{
    vector<int> return_num;
    int Num=num;
    while(num)
    {
        return_num.push_back(num%1000);
        num/=1000;
    }
    if(Num==1)
    {
        return return_num;
    }
    else
    {
        return mul(return_num,stage(Num-1));
    }
}
vector<int> mul(vector<int> num1,vector<int> num2)
{
    vector<int> result(num1.size()+num2.size(),0);
    for(int i=0;i<num1.size();i++)
    {
        for(int j=0;j<num2.size();j++)
        {
            result[i+j]+=num1[i]*num2[j];
        }
    }
    for(int i=1;i<result.size();i++)
    {
        result[i]+=result[i-1]/1000;
        result[i-1]%=1000;
    }
    for(int i=result.size()-1;i>=0;i--)
    {
        if(!result[i]) result.pop_back();
        else break;
    }
    return result;
}
