/* 20150803
 * hanting
 * UVa 12096 - The SetStack Computer
 * C++
 */
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>//set_union,set_intersection
using namespace std;
stack<int> stk;
map<set<int>,int> Map;
vector<set<int> > vec;
int SetID(set<int> &s)
{
    if(Map.count(s)) return Map[s];
    vec.push_back(s);
    return Map[s]=vec.size()-1;
}
set<int> Empty;
void PUSH()
{
    stk.push(SetID(Empty));
}
void DUP(int t)
{
    stk.push(t);
    stk.push(t);
}
void UNION(int t)
{
    int t2=stk.top();
    stk.pop();
    set<int> un;
    set_union(vec[t].begin(),vec[t].end(),vec[t2].begin(),vec[t2].end(),inserter(un,un.begin()));
    stk.push(SetID(un));
}
void INTERSECT(int t)
{
    int t2=stk.top();
    stk.pop();
    set<int> in;
    set_intersection(vec[t].begin(),vec[t].end(),vec[t2].begin(),vec[t2].end(),inserter(in,in.begin()));
    stk.push(SetID(in));
}
void ADD(int t)
{
    set<int> s(vec[stk.top()].begin(),vec[stk.top()].end());
    stk.pop();
    s.insert(t);
    stk.push(SetID(s));
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        while(stk.size()) stk.pop();//initial
        int cmdN;
        cin>>cmdN;
        for(int i=0;i<cmdN;i++)
        {
            string cmd;
            cin>>cmd;
            if(cmd=="PUSH")
            {
                PUSH();
            }
            else
            {
                int top=stk.top();
                stk.pop();
                if(cmd=="DUP")
                {
                    DUP(top);
                }
                else if(cmd=="UNION")
                {
                    UNION(top);
                }
                else if(cmd=="INTERSECT")
                {
                    INTERSECT(top);
                }
                else//ADD
                {
                    ADD(top);
                }
            }
            cout<<vec[stk.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}
