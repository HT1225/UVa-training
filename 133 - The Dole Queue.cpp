/* 20150729
 * hanting
 * UVa 133 - The Dole Queue
 * C++
 */
#include <iostream>
#include <vector>
#include <iomanip>//setw
using namespace std;
int main()
{
    int manN,right,left;//往右k//往左m
    while(cin>>manN>>right>>left and manN)
    {
        int posR=-1,posL=0;
        vector<int> vec(manN);
        for(int i=0;i<manN;i++)
        {
            vec[i]=i+1;
        }
        int cnt=0;
        while(cnt<vec.size())//數到陣列元素都變-1
        {
            for(int i=0;i<right;i++)//往右走
            {
                posR++;
                posR%=manN;
                if(vec[posR]==-1) i--;
            }
            for(int i=0;i<left;i++)//往左走
            {
                posL--;
                posL=(posL+manN)%manN;
                if(vec[posL]==-1) i--;
            }
            if(posR==posL)
            {
                cnt++;
                cout<<setw(3)<<vec[posR]<<(cnt<vec.size() ? ",":"");
            }
            else
            {
                cnt+=2;
                cout<<setw(3)<<vec[posR]<<setw(3)<<vec[posL]<<(cnt<vec.size() ? ",":"");
            }
            vec[posR]=vec[posL]=-1;
        }
        cout<<endl;
    }
    return 0;
}
