/* 20150803
 * hanting
 * UVa 1592 - Database
 * C++
 */
#include <iostream>
#include <map>
#include <cstring>//strtok
using namespace std;
map<string,int> ID;
int sum=0;
int idx=1;
int StrID(string str)
{
    if(ID[str]) return ID[str];
    return ID[str]=idx++;
}
int main()
{
    int row,col;
    while(cin>>row>>col)
    {
        cin.get();
        string table[row+2][col+2];
        string tmp;
        for(int i=1;i<=row;i++)
        {
            getline(cin,tmp);//注意要讀一整行再做切割
            char *pch=strtok((char*)tmp.c_str(),",");

            int j=1;
            while(pch)
            {
                table[i][j++]=pch;
                pch=strtok(NULL,",");
            }
        }
        int IDtable[row+2][col+2];//預處理,將字串予編號
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                IDtable[i][j]=StrID(table[i][j]);
            }
        }
        bool Yes=true;//找到一項即可
        for(int i=1;i<=col and Yes;i++)
        {
            for(int j=i+1;j<=col and Yes;j++)
            {
                map<int,int> Map;//Map[idx]=列
                for(int k=1;k<=row and Yes;k++)
                {
                    int idx=IDtable[k][i]*100000+IDtable[k][j];
                    if(Map.count(idx))
                    {
                        cout<<"NO"<<endl;
                        cout<<Map[idx]<<" "<<k<<endl;
                        cout<<i<<" "<<j<<endl;
                        Yes=false;
                    }
                    else
                    {
                        Map[idx]=k;
                    }
                }
            }
        }
        if(Yes) cout<<"YES"<<endl;

    }
    return 0;
}
