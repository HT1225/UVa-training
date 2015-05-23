/*20150523 hanting*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N,Q;
    int Case=1;
    while(cin>>N>>Q && N+Q)
    {
        vector<int> vec;
        for(int i=0;i<N;i++)
        {
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end());
        cout<<"CASE# "<<Case++<<":"<<endl;
        for(int i=0;i<Q;i++)
        {
            int temp;
            cin>>temp;
            vector<int>::iterator it=find(vec.begin(),vec.end(),temp);
            if(it!=vec.end())
            {
                cout<<temp<<" found at "<<it-vec.begin()+1<<endl;
            }
            else
            {
                cout<<temp<<" not found"<<endl;
            }
        }
    }
    return 0;
}
