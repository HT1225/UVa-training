/* 20150728
 * hanting
 * UVa 1584 - Circular Sequence
 * C++
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string str;
        cin>>str;
        string mini=str;
        for(int i=0;i<str.size();i++)
        {
           string tmp=str.substr(i+1)+str.substr(0,i+1);
           if(tmp<mini) mini=tmp;
        }
        cout<<mini<<endl;
    }

    return 0;
}
