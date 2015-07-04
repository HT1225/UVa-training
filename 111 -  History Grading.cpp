/* 20150704
 * hanting
 * [UVA] 111 -  History Grading
 *
 */
#include <iostream>
#include <sstream>
using namespace std;

int N;//event_num
istream& operator>>(istream& in,int *arr)
{
    string str;
    getline(in,str);
    stringstream sin(str);
    for(int i=1;i<=N;i++)//輸入1 3 4 2 表示順序為 event1,event4,event2,event3
    {
        int tmp;
        sin>>tmp;
        arr[tmp]=i;
    }
    return in;
}
int LCS(int *a,int *b)
{
    int table[N+1][N+1];
    fill(table[0],table[0]+(N+1)*(N+1),0);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(a[i]==b[j])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    return table[N][N];
}
int main()
{
    cin>>N;
    cin.get();
    int ans[N+1];
    cin>>ans;
    int student[N+1];
    while(cin>>student)
    {
        int lcs=LCS(ans,student);
        cout<<lcs<<endl;
    }
    return 0;
}
