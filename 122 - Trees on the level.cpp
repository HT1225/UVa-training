/* 20150818
 * hanting
 * UVa 122 - Trees on the level
 * C++
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>//sort
#include <sstream>
using namespace std;
struct Node
{
    int id;
    string route;
    Node(int x,string str):id(x),route(str){}
    bool operator<(const Node &n)const
    {
        if(route.size()<n.route.size()) return true;
        else if(route.size()==n.route.size())return route<n.route;
        else return false;
    }
};
inline string Parent(string &str)
{
    return str.substr(0,str.size()-1);
}
string str;
vector<Node> vec;
map<string,int> Map;
bool Input()
{
    Map.clear();
    vec.clear();
    bool input=false;
    while(cin>>str and str!="()")
    {
        input=true;
        stringstream sin(str);
        char ch;
        int x;
        string tmp;
        sin>>ch>>x>>ch>>tmp;//( 11 , LL)
        tmp.erase(tmp.size()-1);//右括弧
        vec.push_back(Node(x,tmp));
    }
    return input;
}
int main()
{
    while(Input())
    {
        sort(vec.begin(),vec.end());
        bool NO=vec[0].route!="";
        Map[""]=1;
        for(int i=1;i<vec.size() and !NO;i++)
        {
            string par=Parent(vec[i].route);//求父節點
            if(Map.count(par)==0 or Map.count(vec[i].route)!=0)
            {
                NO=true;
                break;
            }
            Map[vec[i].route]++;
        }
        if(NO)
        {
            cout<<"not complete"<<endl;
        }
        else
        {
            for(int i=0;i<vec.size()-1;i++)
            {
                cout<<vec[i].id<<" ";
            }
            cout<<vec.back().id<<endl;
        }
    }
    return 0;
}
