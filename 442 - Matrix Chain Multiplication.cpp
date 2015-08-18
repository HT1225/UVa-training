/* 20150818
 * hanting
 * UVa 442 - Matrix Chain Multiplication
 * C++
 */
#include <iostream>
#include <stack>
#include <map>
using namespace std;
struct Matrix
{
    int row,col;
    int times;
    Matrix(int r=0,int c=0,int t=0):row(r),col(c),times(t){}
    Matrix operator*(Matrix &m)
    {
        int t= (col==m.row ? row*col*m.col:-1);//判斷是否可乘，負數表示不行
        return Matrix(row,m.col,t);
    }
};
stack<Matrix> stk;
map<char,Matrix> Map;
int main()
{
    int N;
    while(cin>>N)
    {
        Map.clear();
        char ch;
        int r,c;
        for(int i=0;i<N;i++)
        {
            cin>>ch>>r>>c;
            Map[ch]=Matrix(r,c);
        }
        string str;
        while(cin>>str)
        {
            while(stk.size()) stk.pop();//initial
            bool valid=true;
            int sum=0;
            for(int i=0;i<str.size() and valid;i++)
            {
                if(str[i]==')')//從stack中pop兩個出來做乘法
                {
                    if(stk.size()<2)
                    {
                        valid=false;
                    }
                    else
                    {
                        Matrix t1=stk.top(); stk.pop();
                        Matrix t2=stk.top(); stk.pop();
                        Matrix result(t2*t1);
                        if(result.times<0) valid=false;
                        else
                        {
                            sum+=result.times;
                            stk.push(result);
                        }
                    }
                }
                else if(str[i]!='(')
                {
                    Matrix tmp=Map[str[i] ];
                    stk.push(tmp);
                }
            }
            if(valid)
            {
                cout<<sum<<endl;
            }
            else
            {
                cout<<"error"<<endl;
            }
        }
    }
    return 0;
}
