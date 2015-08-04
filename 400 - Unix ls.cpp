/* 20150803
 * hanting
 * UVa 400 - Unix ls
 * C++
 */
#include <iostream>
#include <vector>
#include <algorithm>//sort
#include <iomanip>//setw
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        cout<<"------------------------------------------------------------"<<endl;
        vector<string> vec(N);
        int maxi=0;
        for(int i=0;i<N;i++)
        {
            cin>>vec[i];
            if(maxi<vec[i].size()) maxi=vec[i].size();
        }
        sort(vec.begin(),vec.end());
        int w;//欄位
        int h;//列
        w=(60-maxi)/(maxi+2)+1;
        h=N/w+(N%w ? 1 : 0);
        string output[h][w];
        int x=0;
        for(int i=0;i<w and x<vec.size();i++)
        {
            for(int j=0;j<h and x<vec.size();j++)
            {
                output[j][i]=vec[x++];
            }
        }

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cout<<setw(j!=w-1 ? maxi+2 : maxi)<<left<<output[i][j];
            }cout<<endl;
        }
    }
    return 0;
}
