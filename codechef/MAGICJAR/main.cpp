#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll val, sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>val;
            sum+=val;
        }
        cout<<(sum-n+1)<<endl;
    }
}
