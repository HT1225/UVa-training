/* 20150801
 * hanting
 * UVa 136 - Ugly Numbers
 * C++
 */
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
    long long init[]={5,3,2,1};
    priority_queue<long long,vector<long long>,greater<long long> > prq(init,init+4);
    map<long long,long long> Map;
    Map[1]=Map[2]=Map[3]=Map[5]=1;
    for(long long i=0;i<1500-1;i++)
    {
        long long x2,x3,x5;
        long long top=prq.top();
        prq.pop();
        x2=top*2;
        x3=top*3;
        x5=top*5;
        if(Map[x2]==0)
        {
            prq.push(x2);
            Map[x2]=1;
        }
        if(Map[x3]==0)
        {
            prq.push(x3);
            Map[x3]=1;
        }
        if(Map[x5]==0)
        {
            prq.push(x5);
            Map[x5]=1;
        }
        cout<<top<<" ";
    }
    cout<<"The 1500'th ugly number is "<<prq.top()<<"."<<endl;
    return 0;
}
