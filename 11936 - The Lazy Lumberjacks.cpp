/*20150131 hanting*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int edge[3];
        cin>>edge[0]>>edge[1]>>edge[2];
        sort(edge,edge+3);
        cout<<(edge[0]+edge[1]>edge[2] ? "OK":"Wrong!!")<<endl;
    }
    return 0;
}
