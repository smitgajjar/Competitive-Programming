//Smit Gajjar
#include <bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0) 
using namespace std;
int main()
{
	io;
	ll n, p;
	cin>>n;
	//vector<ll>a(n);
	map<ll, ll>m;
	for(ll i = 0; i<n; i++)
		cin>>p, m[p]++;
	p=INT_MIN;
	for(auto i: m)
	{
		if(i.first>p)
			 p=i.first;
		
	}
	ll ans=0;
	for(auto i: m)
	{
			ans+=min(i.first*i.second, (abs(i.first-p)*(i.second)));
	}
	cout<<ans<<endl;

}