#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a, b;
		cin>>a>>b;
		vector<bool> prime;
		prime.assign(b+1, 1);
		prime[0]=0;
		prime[1]=0;
		//cout<<endl<<endl;
		for(ll i=2; i*i<=b; i++)
		{
			if(prime[i])
			{
				for(ll p=i*i; p<=b;p+=i)
				{
					prime[p]=0;

				}
			}
		}
		ll count=0;
		if(a<=0)
			a=2;
		sort(prime.begin()+a, prime.end());
		for(auto i=prime.rbegin(); i<=prime.rend()-a; i++)
		{
			if(*i)
				count++;
			else
				break;
		}
		cout<<count<<endl;
	}
}