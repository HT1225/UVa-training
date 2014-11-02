/*20141102 hanting*/
#include <iostream>
#include <vector>
using namespace std;
struct BigNum
{
    vector<int> num;
    void operator+=(BigNum n)
    {
        int R=max(n.num.size(),num.size());
        num.resize(R+1);
        n.num.resize(R+1);
        vector<int> ans(1);
        for(int i=0;i<R;i++)
        {
            ans[i]+=num[i]+n.num[i];
            ans.push_back(ans[i]/1000);
            ans[i]%=1000;
        }
        if(!ans[R]) ans.pop_back();
        num=ans;
    }
    BigNum operator*(BigNum n)
    {
        BigNum ans;
        ans.num.resize(num.size()+n.num.size());
        for(int i=0;i<num.size();i++)
        {
            for(int j=0;j<n.num.size();j++)
            {
                ans.num[i+j]+=num[i]*n.num[j];
            }
        }
        for(int i=1;i<ans.num.size();i++)
        {
            ans.num[i]+=ans.num[i-1]/1000;
            ans.num[i-1]%=1000;
        }
        for(int i=ans.num.size()-1;i>0;i--)
        {
            if(ans.num[i]==0) ans.num.pop_back();
            else break;
        }
        return ans;
    }
    void operator*=(int n)
    {
        vector<int> ans(1);
        for(int i=0;i<num.size();i++)
        {
            ans[i]+=num[i]*2;
            ans.push_back(ans[i]/1000);
            ans[i]%=1000;
        }
        if(!ans[ans.size()-1]) ans.pop_back();
        num=ans;
    }
    friend ostream& operator<<(ostream& out, BigNum& n)
    {
        int first=n.num.size()-1;
        out<<n.num[first];
        for(int i=first-1;i>=0;i--)
        {
            if(n.num[i]<100) out<<0;
            if(n.num[i]<10) out<<0;
            out<<n.num[i];
        }
        return out;
    }
};
BigNum store[1005];
BigNum tree(int n)
{
    if(store[n].num.size()) return store[n];
    else
    {
        for(int i=0;i<n/2;i++)
        {
            store[n]+=tree(i)*tree(n-i-1);
        }
        store[n]*=2;
        if(n%2==1)store[n]+=tree(n/2)*tree(n/2);
        return store[n];
    }
}
int main()
{
    store[0].num.push_back(1);
    store[1].num.push_back(1);
    store[2].num.push_back(2);
    store[3].num.push_back(5);
    int N;
    while(cin>>N)
    {
        tree(N);
        cout<<store[N]<<endl;
    }
    return 0;
}
