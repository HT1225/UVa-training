/*20150208 hanting*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Find(vector<int> num,int i)
{
    vector<int>::iterator itr=find(num.begin(),num.end(),i);
    return (itr!=num.end());
}
int main()
{
    int N;
    while(cin>>N && N)
    {
        int ans=1;
        for(;ans;ans++)
        {
            vector<int> num(N);
            for(int i=0;i<N;i++)
                num[i]=i;
            for(int i=0;i<N;)
            {
                num.erase(num.begin()+i);
                i+=ans-1;
                i%=num.size();
                if(!Find(num,12) || num.size()==1)
                {
                    break;
                }
            }
            if(num.size()==1 && num[0]==12)
            {
                cout<<ans<<endl;
                break;
            }
        }

    }
    return 0;
}
