/* 20150812
 * hanting
 * UVa 221 - Urban Elevations
 * C++
 */
#include <iostream>
#include <vector>
#include <algorithm>//sort,unique
using namespace std;
struct Building
{
    int id;
    double x,y,width,depth,height;
    friend istream& operator>>(istream& in,Building &b)
    {
        in>>b.x>>b.y>>b.width>>b.depth>>b.height;
        return in;
    }
    bool operator<(const Building &B)const
    {
        return (x<B.x) or (x==B.x and y<B.y);
    }
    bool cover(double t)
    {
        return t>=x and t<=x+width;
    }
    bool visible(double x,Building *b,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(b[i].cover(x) and b[i].y<y and b[i].height>=height) return false;
        }
        return true;
    }
};
int main()
{
    int buildingN;
    int Case=1;
    int blank=0;
    while(cin>>buildingN and buildingN)
    {
        if(blank++) cout<<endl;
        Building building[buildingN];
        double xCoor[buildingN*2];
        for(int i=0;i<buildingN;i++)
        {
            cin>>building[i];
            building[i].id=i+1;//編號從1開始
            xCoor[i*2]=building[i].x;
            xCoor[i*2+1]=building[i].x+building[i].width;
        }
        sort(building,building+buildingN);
        sort(xCoor,xCoor+buildingN*2);
        int m=unique(xCoor,xCoor+buildingN*2)-xCoor;
        vector<int> ans;
        ans.push_back(0);

        for(int i=1;i<buildingN;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                double x=(xCoor[j]+xCoor[j+1])/2;
                if(building[i].cover(x) and building[i].visible(x,building,buildingN))
                {
                    ans.push_back(i);
                    break;
                }
            }
        }

        cout<<"For map #"<<Case++<<", the visible buildings are numbered as follows:"<<endl;

        for(int i=0;i<ans.size()-1;i++)
        {
            cout<<building[ans[i]].id<<" ";
        }
        cout<<building[ans.back()].id<<endl;
    }
    return 0;
}
