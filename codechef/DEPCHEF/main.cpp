#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val;
        cin>>n;
        vector<int> a, d, att;
        a.assign(n, 0);
        d.assign(n, 0);
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>d[i];

        att.assign(n, 0);
        att[0]=a[n-1]+a[1];
        att[n-1]=a[n-2]+a[0];
        for(int i=1; i<=n-2; i++)
        {
            att[i]=a[i-1]+a[i+1];
        }
        bool flag=false;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if((d[i]-att[i])>0)
            {
                flag=true;
                if(d[i]>ans)
                {
                    ans=d[i];
                    //cout<<ans<<endl;
                }

            }
        }
        cout<<(flag?ans:-1)<<endl;
    }
}
