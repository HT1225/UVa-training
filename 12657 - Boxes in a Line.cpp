/* 20150820
 * hanting
 * UVa 12657 - Boxes in a Line
 * C++
 */
#include <iostream>
using namespace std;
const int maxn=100000+5;
int Left[maxn],Right[maxn];
#define head 0
#define last 100003
void Link(int L,int R)
{
    Right[L]=R;
    Left[R]=L;
}
void initial(int N)
{
    Link(head,1);
    for(int i=1;i<N;i++)
    {
        Link(i,i+1);
    }
    Link(N,last);
}
int main()
{
    int boxN,cmdN;
    int caseN=1;
    while(cin>>boxN>>cmdN)
    {
        initial(boxN);//串接N個數字
        bool Reverse=false;
        for(int i=0;i<cmdN;i++)
        {
            int cmd,x,y;
            cin>>cmd;
            if(cmd!=4)
            {
                cin>>x>>y;
            }
            else//反轉整條鏈
            {
                Reverse=!Reverse;
            }
            int Lx=Left[x],Rx=Right[x];
            int Ly=Left[y],Ry=Right[y];
            if(Reverse and cmd<3) cmd=3-cmd;
            switch(cmd)
            {
            case 1://把x移動到y左邊
                if(Ly==x) break;//x已經在y左邊
                Link(Ly,x);
                Link(x,y);
                Link(Lx,Rx);
                break;
            case 2://把x移動到y右邊
                if(Ry==x) break;//x已經在y右邊
                Link(y,x);
                Link(x,Ry);
                Link(Lx,Rx);
                break;
            case 3://x與y的位置交換
                if(Lx==y)//y在x左邊
                {
                    Link(Ly,x);
                    Link(x,y);
                    Link(y,Rx);
                }
                else if(Rx==y)//y在x右邊
                {
                    Link(Lx,y);
                    Link(y,x);
                    Link(x,Ry);
                }
                else
                {
                    Link(Lx,y);
                    Link(y,Rx);
                    Link(Ly,x);
                    Link(x,Ry);
                }
                break;
            }
        }
        cout<<"Case "<<caseN++<<": ";
        long long sum=0;
        if(Reverse)
        {
            for(int i=Left[last] ,j=0; i!=head ; i=Left[i],j++)
            {
                if(!(j&1)) sum+=i;
            }
        }
        else
        {
            for(int i=Right[head],j=0 ; i!=last ; i=Right[i],j++)
            {
                if(!(j&1)) sum+=i;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
