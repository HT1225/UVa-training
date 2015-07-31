/* 20150730
 * hanting
 * UVa 213 - Message Decoding
 * C++
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>//count
using namespace std;
string reset(int N)
{
    string str="";
    for(int i=0;i<N;i++)
    {
        str+='0';
    }
    return str;
}
string operator+(string str,int i)
{
    str[str.size()-1]+=1;
    for(int i=str.size()-2;i>=0;i--)
    {
        if(str[i+1]=='2')
        {
            str[i]++;
            str[i+1]='0';
        }
    }
    if(count(str.begin(),str.end(),'1')==str.size())
    {
        str="0"+reset(str.size());
    }
    return str;
}
void BuildKey(vector<string> &key)
{
    key.push_back("0");
    while(key.back().size()<9)
    {
        string last=key.back();
        key.push_back(last+1);
    }

}
int main()
{
    string header;
    vector<string> key;
    BuildKey(key);
    while(getline(cin,header))
    {
        map<string,char> EncodeTable;
        for(int i=0;i<header.size();i++)//編碼頭每個字元依序對應每個code
        {
            char ch=header[i];
            EncodeTable[key[i]]=ch;
        }
        char length[4]={0};
        while(cin>>length[0]>>length[1]>>length[2])
        {
            int codeL=strtol(length,NULL,2);//將010轉成10進位的2
            if(codeL==0) break;//輸入000結束
            while(true)//解碼
            {
                char ch;
                string code="";//將訊息中的01001存起來待等一下解碼
                for(int i=0;i<codeL;i++)
                {
                    cin>>ch;
                    code+=ch;
                }
                if(EncodeTable[code])cout<<EncodeTable[code];
                else break;//編碼111結束解碼
            }
        }
        cout<<endl;
        cin.get();
    }
    return 0;
}
