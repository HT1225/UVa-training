/* 20150814
 * hanting
 * UVa 514 - Rails
 * C++
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
bool CanRestructure(queue<int> &que)
{
    vector<int> from(que.size());
    for(int i=0;i<from.size();i++)
    {//給予from初始值1 2 ...n
        from[i]=i+1;
    }
    stack<int> stk;
    for(int i=0;i<from.size();i++)
    {
        stk.push(from[i]);//車廂一個個進車站
        while(stk.size() and que.front()==stk.top())
        {//若與B的頭一樣就輸出，也就是pop車站的車廂
            stk.pop();
            que.pop();
        }
    }
    if(stk.size()) return false;
    else return true;
}
int main()
{
    int N;
    while(cin>>N and N)
    {
        while(true)
        {
            queue<int> que;
            int num;
            cin>>num;
            if(!num) break;//0跳出
            que.push(num);
            for(int i=1;i<N;i++)
            {
                cin>>num;
                que.push(num);
            }
            if(CanRestructure(que))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
