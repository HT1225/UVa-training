/*20150203 hanting*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int DFS(int *visit,vector<int> *place,int me,int parent,bool *critical,int &time)
{
    int mini=time;
    visit[me]=time++;
    for(int i=0;i<place[me].size();i++)
    {
        int sub=place[me][i];
        int temp=mini;
        if(visit[sub]==-1)
        {
            temp=DFS(visit,place,sub,me,critical,time);
            if(visit[me]==0)//root 是關節點
            {
                if(i>0)
                {
                    critical[me]=true;
                }
            }
            else if(temp>=visit[me])//關節點
            {
                critical[me]=true;
            }
        }
        else if(sub!=parent)
        {
            temp=visit[sub];
        }
        if(temp<mini) mini=temp;
    }
    return mini;
}
int main()
{
    int placeNum=0;
    while(cin>>placeNum && placeNum)
    {
        placeNum++;
        vector<int> place[placeNum];
        string str;
        while(getline(cin,str) && str!="0")
        {
            stringstream sin(str);
            int place1;
            sin>>place1;
            int connect;
            while(sin>>connect)
            {
                place[place1].push_back(connect);
                place[connect].push_back(place1);
            }
        }
        int visit[placeNum];
        fill(visit,visit+placeNum,-1);
        bool critical[placeNum];
        fill(critical,critical+placeNum,false);
        for(int i=0;i<placeNum;i++)
        {
            if(visit[i]==-1)
            {
                int time=0;
                DFS(visit,place,i,-1,critical,time);
            }
        }
        cout<<count(critical,critical+placeNum,1)<<endl;
    }
    return 0;
}
