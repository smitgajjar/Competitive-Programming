//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map<ll, ll>mp;
int main()
{
	// sort(v.begin(), v.end(), compare);
	int t=1;
	cin>>t;
	while(t--)
	{
		mp.clear();
		cin>>n;
		ll a[n];
		for(ll i=0; i<n; i++)
			cin>>a[i];
		for(ll i=1; i<n; i++)
			mp[a[i]-a[i-1]]++;
		ll maxx=INT_MIN, diff, it;
		for(auto p: mp)
		{
			if(p.second>maxx)
			{
				maxx=p.second;
				diff=p.first;
				it=maxx;
			}
		}
		int idx=0;
		if(it!=1)
		{
			for(int i=1; i<n; i++)
			{
				if(a[i]-a[i-1]==diff)
				{
					idx=i-1;
					break;
				}
			}
			int fi=a[idx]-idx*diff;
			for(int i=0; i<n; i++)
			{
				cout<<fi<<' ';
				fi+=diff;
				///cout<<"hi";
			}
		}
		else
		{
			ll diff=0;
			ll fi=a[0];
			ll a1=a[1]-a[0];
			ll a2=a[2]-a[0];
			ll a3=a[3]-a[0];
			ll a4=a[3]-a[2];
			if(a3/(double)a1==3.0)
			{
				diff=a1;
			}
			else if(a2/(double)a4==2.0)
			{
				diff=a4;
			}
			for(ll i=0; i<n; i++)
			{
				cout<<fi<<' ';fi+=diff;
			}


		}
		cout<<endl;
	}
}