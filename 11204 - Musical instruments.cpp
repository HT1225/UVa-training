/*20140806 hanting*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int m,n;
        cin>>m>>n;
        vector<int> a(m);
        for(int i=0;i<n;i++)
        {
            int temp;
            for(int j=0;j<m;j++)
            {
                cin>>temp;
                if(temp==1) a[j]++;

            }
        }
        int ans=1;
        for(int i=0;i<m;i++)
        {
            if(a[i])ans*=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
