#include<bits/stdc++.h>
#define debug(s) cout<<s<<endl<<endl;
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, m, d, vmax1=INT_MIN, v, vmax2=INT_MIN, dmax1=INT_MIN, dmax2=INT_MIN;

		cin>>n>>m;
		map<ll, ll>mp;
		for(int i=0; i<n; i++)
		{
			cin>>d>>v;
			if(mp.find(d)==mp.end() or v>mp[d])
				mp[d]=v;
		}
		for(auto i: mp)
		{
			if(i.second>vmax1)
				vmax1=i.second, dmax1=i.first;
		}
		for(auto i: mp)
		{
			if(i.first!=dmax1 and i.second>vmax2)
				vmax2=i.second;
		}

		cout<<vmax1+vmax2<<endl;
	}
}