/*20140912 hanting*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int blankline=0;
    while(N--)
    {
        if(blankline) cout<<endl;
        int people;
        cin>>people;
        int temp=people;
        vector<int> a(people);
        for(int i=0;i<people;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int A,B,C,D;
        A=0;//first
        B=1;//second
        C=people-2;//last second
        D=people-1;//last
        int sum=0;
        while(people)//consider_sum
        {
            if(people==1)
            {
                sum+=a[A];
                people--;
            }
            else if(people==2)
            {
                sum+=a[B];
                people-=2;
            }
            else if(people==3)
            {
                sum+=a[B]+a[A]+a[D];
                people-=3;
            }
            else
            {
                if(a[B]-a[A]>a[C]-a[B])
                {
                    sum+=a[C]+a[A]+a[D]+a[A];
                }
                else
                {
                    sum+=a[B]+a[A]+a[D]+a[B];
                }
                people-=2;
                C=people-2;
                D=people-1;
            }
        }
        cout<<sum<<endl;
        people=temp;
        A=0;//first
        B=1;//second
        C=people-2;//last second
        D=people-1;//last
        while(people)//cout_tread
        {
            if(people==1)
            {
                cout<<a[A]<<endl;
                people--;
            }
            else if(people==2)
            {
                cout<<a[A]<<" "<<a[B]<<endl;
                people-=2;
            }
            else if(people==3)
            {
                cout<<a[A]<<" "<<a[B]<<endl;
                cout<<a[A]<<endl;
                cout<<a[A]<<" "<<a[D]<<endl;
                people-=3;
            }
            else
            {
                if(a[B]-a[A]>a[C]-a[B])
                {
                    cout<<a[A]<<" "<<a[C]<<endl;
                    cout<<a[A]<<endl;
                    cout<<a[A]<<" "<<a[D]<<endl;
                    cout<<a[A]<<endl;
                }
                else
                {
                    cout<<a[A]<<" "<<a[B]<<endl;
                    cout<<a[A]<<endl;
                    cout<<a[C]<<" "<<a[D]<<endl;
                    cout<<a[B]<<endl;
                }
                people-=2;
                C=people-2;
                D=people-1;
            }
        }
        blankline=1;
    }
    return 0;
}
