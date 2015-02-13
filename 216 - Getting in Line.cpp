/*20150213 hanting*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
struct coordinate
{
    int x,y;
    friend istream& operator>>(istream& in,coordinate &com)
    {
        in>>com.x>>com.y;
        return in;
    }
    friend ostream& operator<<(ostream& out,coordinate &com)
    {
        out<<"("<<com.x<<","<<com.y<<")";
        return out;
    }
    friend double operator-(coordinate &a,coordinate &b)
    {
        double ans;
        ans=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        return sqrt(ans)+16;
    }
};
void DFS(int *visit,int N,int now,int parent,coordinate *com,vector<coordinate> &ShortestPath,double &sum,double &Shortsum,vector<coordinate> &path)
{
    visit[now]=1;
    path.push_back(com[now]);
    double distance=0;
    if(parent!=-1)
    {
        distance=(com[parent] - com[now]);
        sum+= distance;
    }
    if(!count(visit,visit+N,0))//形成hamilton path
    {
        if(Shortsum>sum || Shortsum==-1)
        {
            Shortsum=sum;
            ShortestPath=path;
        }
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            if(visit[i]==0) DFS(visit,N,i,now,com,ShortestPath,sum,Shortsum,path);
        }
    }
    visit[now]=0;
    path.pop_back();
    sum-=distance;
}
int main()
{
    int N;
    int times=0;
    while(cin>>N && N)
    {
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<++times<<endl;
        coordinate com[N];
        for(int i=0;i<N;i++)
        {
            cin>>com[i];
        }
        int visit[N];
        vector<coordinate> ShortestPath;
        fill(visit,visit+N,0);
        double pathsum=0;
        double Shortsum=-1;
        vector<coordinate> path;
        for(int i=0;i<N;i++)
        {
            if(visit[i]==0)
            {
                DFS(visit,N,i,-1,com,ShortestPath,pathsum,Shortsum,path);
            }
        }
        double sum=0;
        for(int i=1;i<ShortestPath.size();i++)
        {
            double distance=(ShortestPath[i-1]-ShortestPath[i]);
            cout<<fixed<<setprecision(2);
            cout<<"Cable requirement to connect "<<ShortestPath[i-1]<<" to "<<ShortestPath[i]<<" is "<<distance<<" feet."<<endl;
            sum+=distance;
        }
        cout<<"Number of feet of cable required is "<<sum<<"."<<endl;
    }
    return 0;
}
