/* 20150817
 * hanting
 * UVa 11988 - Broken Keyboard
 * C++
 */
#include <iostream>
using namespace std;
#define head 100001
#define last 100002
int Left[100003];
int Right[100003];

void Link(int L,int R)
{
    Left[R]=L;
    Right[L]=R;
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        int cur=head;
        Link(head,last);
        Right[last]=-1;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='[')
            {
                cur=head;
            }
            else if(str[i]==']')
            {
                cur=Left[last];
            }
            else
            {
                Link(i,Right[cur]);
                Link(cur,i);
                cur=Right[cur];
            }
        }
        int now=Right[head];
        while(now!=last)
        {
            cout<<str[now];
            now=Right[now];
        }

        cout<<endl;
    }
    return 0;
}
