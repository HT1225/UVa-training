/*20150202 hanting*/
//  在10進位下，一個數若是9的倍數，則這個數字的每個位數相加的總和一定也是9的倍數;
//  舉個例子，81(10-based)，8+1=9，9%9==0 -> 是9的倍數  ;
//  依此原則推出:
//  當這個數字R的每個位數總和=sum，而sum是n的倍數，
//  則 N=n+1;
#include <iostream>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        int sum=0;
        int Max=1;
        for(int i=0;i<str.size();i++)
        {
            int R=0;
            if(isdigit(str[i])) R=str[i]-48;
            else if(isupper(str[i])) R=str[i]-55;//'A'-10
            else if(islower(str[i])) R=str[i]-61;//'a'-36
            sum+=R;
            if(R>Max) Max=R;
        }
        for(int i=Max;i<=62;i++)
        {
            if(sum%i==0)
            {
                cout<<i+1<<endl;//所求N=i+1
                break;
            }
            else if(i==62) cout<<"such number is impossible!"<<endl;
        }
    }
    return 0;
}
