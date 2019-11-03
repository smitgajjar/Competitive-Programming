#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

bool isPrime(ll i)
{
    for(long j=2; j<=sqrt(i); j++)
    {
        if(i%j==0)
        {
            return 0;
            break;
        }

    }
    if(i!=1)
    return 1;
}
void findPrime(ll m, ll n)
{
    ll i;
    if(m>=1)
    {
    for(i=m; i<=n; i++)
    {
        if(isPrime(i))
        {
            cout<<i<<endl;
        }
    }
    }
}

int main()
{
    int t;
    cin>>t;
	while(t--)
    {
        ll m, n;
        cin>>m>>n;
        findPrime(m, n);
    }
    return 0;

}
