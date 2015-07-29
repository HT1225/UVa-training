/* 20150729
 * hanting
 * UVa 489 - Hangman Judge
 * C++
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    while(cin>>N and N!=-1)
    {
        string ans;
        string guess;
        cin>>ans>>guess;
        int AnsTable[123]={0};
        int AnsCnt=0,GuessCnt=0;
        for(int i=0;i<ans.size();i++)
        {
            int ch=ans[i];
            if(!AnsTable[ch])
            {
                AnsTable[ch]=1;
                AnsCnt++;
            }
        }
        int wrong=0;
        for(int i=0;i<guess.size() and AnsCnt!=GuessCnt;i++)
        {
            int ch=guess[i];
            if(AnsTable[ch]==0)
            {
                wrong++;
            }
            else if(AnsTable[ch]==1)
            {
                AnsTable[ch]++;
                GuessCnt++;
            }
        }
        bool Win=AnsCnt==GuessCnt;
        cout<<"Round "<<N<<endl;
        if(wrong<7)
        {
            if(Win) cout<<"You win."<<endl;
            else cout<<"You chickened out."<<endl;
        }
        else
            cout<<"You lose."<<endl;
    }

    return 0;
}
