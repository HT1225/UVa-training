/* 20150702
 * hanting
 * [UVA] 540 - Team Queue
 *
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int N;
    int Sce=0;
    while(cin>>N and N)
    {
        cout<<"Scenario #"<<++Sce<<endl;
        map<int,int> team;
        vector<int> List[N];
        for(int i=0;i<N;i++)
        {
            int num;
            cin>>num;
            for(int j=0;j<num;j++)
            {
                int tmp;
                cin>>tmp;
                team[tmp]=i;//輸入的數字在哪一個team
            }
        }
        string str;
        vector<int> order;//team排隊的順序
        int x=0;
        int dex=0;
        while(cin>>str and str!="STOP")
        {
            if(str=="ENQUEUE")
            {
                int enqueueNum;
                cin>>enqueueNum;
                int TeamOfNum=team[enqueueNum];
                if(List[TeamOfNum].size()==0)
                {
                    order.push_back(TeamOfNum);
                }
                List[TeamOfNum].push_back(enqueueNum);//插入team中
            }
            else if(str=="DEQUEUE")
            {
                int tmp=order[dex];
                cout<<List[tmp][0]<<endl;
                List[tmp].erase(List[tmp].begin());
                if(List[tmp].size()==0) dex++;
            }
        }
        cout<<endl;
    }
    return 0;
}
