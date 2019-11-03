#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(vector<ll> a, ll n)
{
	ll cnt0=0, val;
	vector<ll>prexor(n);
	map<ll, pair<ll, ll>>mp;
	prexor[0]=a[0];
	for(ll i=1; i<n; i++)
	{
		prexor[i]=prexor[i-1]^a[i];
	}
	for(ll i=0; i<n; i++)
	{
		val=prexor[i];
		if(mp.find(val)!=mp.end())
		{
			// cout<<val<<endl;

			cnt0+=(i*mp[val].first-mp[val].first-mp[val].second);	
		}
		
		mp[val].first++; 
		mp[val].second+=i;	
		// cnt0+=(ll)mp[val].size();
		if(val==0) cnt0+=i;
		// mp[val].push_back({mp[val].first++, mp[val]->second+i});	
	}
	return cnt0;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>a(n);
		for(ll i=0; i<n; i++)
			cin>>a[i];
		cout<<solve(a, n)<<endl;
	}
}