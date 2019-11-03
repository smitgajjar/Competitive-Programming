#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a, b, k, n;
        cin>>n>>a>>b>>k;
        if(b<a) swap(a, b);
        ll ans, lcm=(a*b)/__gcd(a, b);

        ans=(b%a!=0?(n/a + n/b - n/lcm):(n/a -n/b));

        cout<<(ans>=k?"Win\n":"Lose\n");


    }

}
