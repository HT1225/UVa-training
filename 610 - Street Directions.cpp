/*20150131 hanting*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Find(vector<int> &vec,int i)
{
    vector<int>::iterator it=find(vec.begin(),vec.end(),i);
    return (it!=vec.end());
}
int DFS(int *visit,vector<int> *node,int vertex,int parent,vector<int> *store)
{
    static int time=0;
    int mini=time;
    visit[vertex]=time++;
    for(int i=0;i<node[vertex].size();i++)
    {
        int temp=mini;
        if(visit[ node[vertex][i] ]==-1)
        {
            store[vertex].push_back(node[vertex][i]);//路徑儲存
            temp=DFS(visit,node,node[vertex][i],vertex,store);
            if(temp>visit[vertex])//找橋
            {
                store[ node[vertex][i] ].push_back(vertex);
            }
        }
        else if(node[vertex][i]!=parent)//其他路徑//backedge
        {//若已存1 3 不必存3 1
            if(!Find(store[ node[vertex][i] ],vertex))store[vertex].push_back(node[vertex][i]);
            temp=visit[  node[vertex][i] ];
        }
        if(temp<mini) mini=temp;

    }
    return mini;//由backedge能回溯的最小visit
}
int main()
{
    int nodeNum,connectNum;
    int Times=0;
    while(cin>>nodeNum>>connectNum && nodeNum+connectNum)
    {
        cout<<++Times<<endl<<endl;
        vector<int> node[nodeNum+1];
        for(int i=0;i<connectNum;i++)
        {
            int a,b;
            cin>>a>>b;
            node[a].push_back(b);
            node[b].push_back(a);
        }

        int visit[nodeNum+1];
        vector<int> store[nodeNum+1];
        fill(visit,visit+nodeNum+1,-1);
        for(int i=1;i<=nodeNum;i++)
        {
            if(visit[i]==-1)
            {
                DFS(visit,node,i,-1,store);
            }
        }
        for(int i=1;i<=nodeNum;i++)
        {
            sort(store[i].begin(),store[i].end());
            for(int j=0;j<store[i].size();j++)
            {
                cout<<i<<" "<<store[i][j]<<endl;
            }
        }
        cout<<"#"<<endl;
    }
    return 0;
}
