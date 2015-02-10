/*20150210 hanting*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int num;
        cin>>num;
        int relatives[num];
        for(int i=0;i<num;i++)
        {
            cin>>relatives[i];
        }
        sort(relatives,relatives+num);
        int medium=relatives[num/2];
        int distance=0;
        for(int i=0;i<num;i++)
        {
            distance+=relatives[i]>medium ? relatives[i]-medium : medium-relatives[i];
        }
        cout<<distance<<endl;
    }
    return 0;
}
