/*20150219 hanting*/
//以10進位的11為例，11有2個1，先建立2個盒子A,B，分別代表十位數與個位數，
//假設一個數902，
//要判斷其為11的倍數，
//先從個位數開始，2放個位數，0放十位數，9放個位數，
//盒子值為11，是11的倍數，則902就是11的倍數，
//
//這一題以二進制表示
//131071(十進位)=11111111111111111(二進位) 17個1
//那麼就建立17個盒子，分別代表2的i次方，0<=i<17，
//照此方法將輸入的二進位值放入，再來判斷盒子值是否為131071的倍數

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N=131071;
    string str;
    while(getline(cin,str))
    {
        while(str.find('#')>=str.size())//讀到終止
        {
            string temp;
            getline(cin,temp);
            str+=temp;
        }
        int arr[17]={0};
        int StrSize=str.size()-1;//remove #
        for(int i=StrSize-1;i>=0;i--)
        {
            arr[i%17]+=str[i]-48;
        }

        long long sum=0;
        for(int i=0;i<17;i++)
        {
            sum+=arr[i]*pow(2.,i);
        }
        if(sum%131071==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
