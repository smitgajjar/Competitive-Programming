#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, cnt=0;
        float value;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            cin>>value;
            if(value>=((float)n/2))
                cnt++;
        }
        cout<<cnt<<endl;
    }
}
