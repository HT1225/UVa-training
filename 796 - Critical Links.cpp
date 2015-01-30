/*20150131 hanting*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int DFS(vector<int> *vertex,int node,int parent,int *visit,vector<int> *store)
{
    static int Count=0;
    int mini=Count;
    visit[node]=Count++;
    for(int i=0;i<vertex[node].size();i++)
    {
        int temp=mini;
        if(visit[ vertex[node][i] ]==-1)/*子節點 沒拜訪過的*/
        {
            temp=DFS(vertex,vertex[node][i],node,visit,store);
            if(temp>visit[node])/*橋*/
            {
                int x=node;
                int y=vertex[node][i];
                if(x>y) swap(x,y);
                store[x].push_back(y);
            }
        }
        else if(vertex[node][i]!=parent)/*拜訪過 判斷回溯*/
        {
            temp=visit[ vertex[node][i] ];
        }
        if(mini>temp) mini=temp;
    }
    return mini;
}

int main()
{
    int N;
    while(cin>>N)
    {
        vector<int> vertex[N];
        vector<int> store[N];
        int visit[N];
        fill(visit,visit+N,-1);
        for(int i=0;i<N;i++)
        {
            int server,connectNum,connect;
            char c;
            cin>>server>>c>>connectNum>>c;
            for(int j=0;j<connectNum;j++)
            {
                cin>>connect;
                vertex[server].push_back(connect);
            }
        }
        for(int i=0;i<N;i++)
        {
            if(visit[i]==-1)
            {
                DFS(vertex,i,-1,visit,store);
            }
        }
        int count=0;
        for(int i=0;i<N;i++)
        {
            count+=store[i].size();
        }
        cout<<count<<" critical links"<<endl;
        for(int i=0;i<N;i++)
        {
            sort(store[i].begin(),store[i].end());
            for(int j=0;j<store[i].size();j++)
            {
                cout<<i<<" - "<<store[i][j]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
