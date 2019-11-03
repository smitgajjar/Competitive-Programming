#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll modi(ll a, ll m=1000000007)
{

    ll mi = m, y = 0, x = 1;

    while (a > 1)
    {
        ll quo = a/m;
        ll t = m ;
        m = a % m;
        a = t;
        t = y;
        y = x - quo * y;
        x = t;
    }

    if (x < 0)
        x = x + mi;
    return x;
}
ll mypow(ll B,ll P,ll M)
{
    ll num1=1,num2=B;
    while(P)
    {
        if(P & 1)
        {
            num1=(num1*num2)%M;
        }
        num2=(num2*num2)%M;
        P/=2;
    }
    return num1;
}

int main()
{
    int t;
    ll ans1, M=1000000007,m2;
    string a,b;
    cin>>t;
    while(t--)
    {
        long n, k, m;
        cin>>n>>k>>m;
        if(m%2)
        {
            a=to_string(n);
            b=to_string(m/2+1);
            int x=a.size();
            int
            y=b.size();

            ll base=0,power=0, ans;

            for(ll i=0; i<x; i++)
            {
                base=((base*10)+(a[i]-'0'))%M;
            }
            m2=M-1;
            for(ll i=0; i<y; i++)
            {
                power=((power*10)+(b[i]-'0'))%m2;
            }
            ans1=mypow(base,power,M);

            a=to_string(n-1);
            b=to_string(m/2+1);

            x=a.size();
            y=b.size();

             base=0,power=0;

            for(ll i=0; i<x; i++)
            {
                base=((base*10)+(a[i]-'0'))%M;
            }
            m2=M-1;
            for(ll i=0; i<y; i++)
            {
                power=((power*10)+(b[i]-'0'))%m2;
            }
            ll ans2=mypow(base,power,M);
            ans=(((ans1-ans2+M)%M)*modi(ans1))%M;
            cout<<ans<<endl;
        }
        else
        {
            a=to_string(n);
            b=to_string(m/2);
            int x=a.size();
            int
            y=b.size();

            ll base=0,power=0, ans, ans1, ans2;

            for(ll i=0; i<x; i++)
            {
                base=((base*10)+(a[i]-'0'))%M;
            }
            m2=M-1;
            for(ll i=0; i<y; i++)
            {
                power=((power*10)+(b[i]-'0'))%m2;
            }
            ans1=mypow(base,power,M);


            a=to_string(n-1);
            b=to_string(m/2);
            x=a.size();
            y=b.size();

            base=0,power=0;

            for(ll i=0; i<x; i++)
            {
                base=((base*10)+(a[i]-'0'))%M;
            }
            m2=M-1;
            for(ll i=0; i<y; i++)
            {
                power=((power*10)+(b[i]-'0'))%m2;
            }
            ans2=mypow(base,power,M);
            ans=((((((k+n)%M)*(ans1))%M - (((k+n-1)%M)*(ans2))%M +M)%M)*modi((((k+n)%M)*(ans1))%M) )%M;
            cout<<ans<<endl;
        }



    }

    return 0;
}
