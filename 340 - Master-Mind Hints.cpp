/* 20150728
 * hanting
 * UVa 340 - Master-Mind Hints
 * C++
 */
#include <iostream>
#include <iomanip>//setw
using namespace std;
int main()
{
    int gameN=1;
    int numN;
    while(cin>>numN and numN)
    {
        int ans[numN];
        for(int i=0;i<numN;i++)
        {
            cin>>ans[i];
        }
        int sum=0;
        cout<<"Game "<<gameN++<<":"<<endl;
        do
        {
            int A=0,B=0;
            int temp[numN];
            copy(ans,ans+numN,temp);
            sum=0;
            int guess[numN];
            for(int i=0;i<numN;i++)
            {
                cin>>guess[i];
                sum+=guess[i];
            }
            /*check*/
            //count A
            for(int i=0;i<numN;i++)
            {
                if(temp[i]==guess[i])
                {
                    A++;
                    temp[i]=-1;
                    guess[i]=-2;
                }
            }
            //count B
            for(int i=0;i<numN;i++)//ans
            {
                for(int j=0;j<numN;j++)//guess
                {
                    if(guess[j]==temp[i])
                    {
                        B++;
                        temp[i]=-1;
                        guess[j]=-2;
                    }
                }
            }
            if(sum)cout<<setw(5)<<"("<<A<<","<<B<<")"<<endl;
        }while(sum);
    }
    return 0;
}
