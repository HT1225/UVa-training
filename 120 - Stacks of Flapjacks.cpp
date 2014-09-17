/*20140917 hanting*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream sin(s);
        vector<int> a;
        int num;
        while(sin>>num)
            a.push_back(num);
        int flip[a.size()];
        for(int i=0;i<a.size();i++)
        {
            if(i!=0) cout<<" ";
            cout<<a[i];
            flip[i]=a.size()-i;
        }
        cout<<endl;
        int test_sort=1;
        int largest;
        for(int i=a.size()-1;i>=0 && test_sort;i--)
        {
            test_sort=0;
            largest=i;
            for(int j=0;j<i;j++)//find the largest number
            {
                if(a[j]>a[largest])
                {
                    largest=j;
                }
            }
            if(largest!=i)
            {
                if(largest!=0)//take it to the first
                {
                    cout<<flip[largest]<<" ";
                    reverse(a.begin(),a.begin()+largest+1);
                }
                cout<<flip[i]<<" ";
                reverse(a.begin(),a.begin()+i+1);//and then reverse to i
            }
            for(int j=0;j<a.size()-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    test_sort=1;
                    break;
                }
            }
        }
        cout<<0<<endl;
    }
    return 0;
}
