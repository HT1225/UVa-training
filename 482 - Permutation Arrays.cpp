#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    int blank=0;
    cin>>N;
    while(N--)
    {
        if(blank) cout<<endl;
        vector<int> a;
        do
        {
            int temp;
            cin>>temp;
            a.push_back(temp);
        }while(cin.get()!='\n');
        vector<string> b;
        do
        {
            string temp;
            cin>>temp;
            b.push_back(temp);
        }while(cin.get()!='\n');
        vector<string> ans(a.size());
        for(int i=0;i<a.size();i++)
        {
            ans[a[i]-1]=b[i];
        }
        for(int i=0;i<a.size();i++)
        {
            cout<<ans[i]<<endl;
        }
        blank=1;
    }
    return 0;
}
