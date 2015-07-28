/* 20150728
 * hanting
 * UVa 1583 - Digit Generator
 * C++
 */
#include <iostream>
using namespace std;
const int MAXN=99999+9*5;
inline int Generate(int &n)
{
    return n+n%10+n/10%10+n/100%10+n/1000%10+n/10000%10;
}
int main()
{
    /*Build Table*/
    int table[MAXN]={0};
    for(int i=100000;i>=0;i--)//倒著回來可得min
    {
        table[Generate(i)]=i;
    }
    int N;
    cin>>N;
    while(N--)
    {
        int num;
        cin>>num;
        cout<<table[num]<<endl;
    }
    return 0;
}
