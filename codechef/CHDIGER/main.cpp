#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        ll n, temp;
        cin>>n>>d;
        temp=n;
        int len=0;
        while(temp!=0)
        {
            temp/=10;
            len++;
        }
        temp=n;
        vector<int> v(len, 0);
        int k=0, last, minv=INT_MAX, mini=0;
        while(temp!=0)
        {
            last=temp%10;
            v[len-1-k]=last;
            temp/=10;
            k++;
        }
        int idx=mini, init=0;
        bool flag=0;
        vector<int>ans;
        while(1)
        {
            minv=INT_MAX;
            for(int i=init; i<len; i++)
            {
                if(v[i]<minv && v[i]<=d)
                {
                    minv=v[i];
                    mini=i;
                    flag=1;
                }
            }
            if(!flag || mini==len)
            {
                break;
            }
            else
            {
                ans.push_back(minv);
                init=mini+1;
                flag=0;
            }

        }
        int l=ans.size();
        for(int i: ans)
            cout<<i;

        for(int i=l; i<len; i++)
            cout<<d;
        cout<<endl;


    }
}
