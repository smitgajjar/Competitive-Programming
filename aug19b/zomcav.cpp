#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// void add(ll &a, ll l, ll r,ll  n)
// {
// 	a[l]++;
// 	if(r!=n-1)
// 		a[r+1]-=1
// }
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, l, r;
		cin>>n;
		ll c[n]={0}, h[n]={0}, a[n]={0};
		for(ll i=0; i<n; i++)
		{
			cin>>c[i];
		}
		for(ll i=0; i<n; i++)
		{
			cin>>h[i];
		}
		for(ll i=0; i<n; i++)
		{
			l=max(i-c[i], 0LL);
			r=min(i+c[i], n-1);
			a[l]++;
			if(r!=n-1)
			{
				a[r+1]--;
			}
		}
		for(ll i=1; i<n; i++)
		{
			a[i]+=a[i-1];
			// cout<<a[i]<<' ';
		}
		// cout<<endl;
		bool flag=1;
		sort(a, a+n);
		sort(h, h+n);

		for(ll i=0; i<n; i++)
		{
			if(a[i]!=h[i])
			{
				flag=0;
				break;
			}
		}

		if(flag)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<'\n';


	}
}