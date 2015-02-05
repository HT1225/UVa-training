/*20140205 hanting*/
/*這題的評判標準只看數字部分*/
//AC是team與ans一模一樣
//PE是只要數字部分順序一樣就行了
//
//例如:
//  11 23 和 1 123  這樣算PE
//  AABBC 和 AABBB  這樣也算PE
//  AABB1 和 AABC1  這樣也算PE
//  AA3BB 和 AA4BB  這樣就是WA
#include <iostream>
using namespace std;
int main()
{
    int team,ans;
    int times=0;
    while(cin>>team && team)
    {
        cin.get();
        string TeamOutput="";
        for(int i=0;i<team;i++)
        {
            string temp;
            getline(cin,temp);
            TeamOutput+=temp;
        }
        string AnsOutput="";
        cin>>ans;
        cin.get();
        for(int i=0;i<ans;i++)
        {
            string temp;
            getline(cin,temp);
            AnsOutput+=temp;
        }
        string TeamNum="";
        string AnsNum="";
        for(int i=0;i<TeamOutput.size();i++)
        {
            if(isdigit(TeamOutput[i])) TeamNum+=TeamOutput[i];
        }
        for(int i=0;i<AnsOutput.size();i++)
        {
            if(isdigit(AnsOutput[i])) AnsNum+=AnsOutput[i];
        }

        bool AC=1,PE=1;
        if(TeamNum==AnsNum)
        {
            if(TeamOutput!=AnsOutput || team!=ans) AC=0;
        }
        else
        {
            AC=0;
            PE=0;
        }
        if(AC) cout<<"Run #"<<++times<<": Accepted"<<endl;
        else if(PE) cout<<"Run #"<<++times<<": Presentation Error"<<endl;
        else cout<<"Run #"<<++times<<": Wrong Answer"<<endl;
    }
    return 0;
}
