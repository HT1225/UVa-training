/*20150208 hanting*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        int sum=0;
        int level=1;//第1級(1,1) 第二級(1,2),(2,1)......
        while(sum+level<N) sum+=level++;
        //N在level級
        int step=N-sum;//N在level的第step個
        int levelSum=level+1;//N所在的那level，其總和//第n級總和=n+1
        int fst,sec;
        if(level&1)//奇數級 (遞減,遞增)
        {
            fst=levelSum-step;
            sec=0+step;
        }
        else//偶數級 (遞增,遞減)
        {
            fst=0+step;
            sec=levelSum-step;
        }

        cout<<"TERM "<<N<<" IS "<<fst<<"/"<<sec<<endl;
    }

    return 0;
}
