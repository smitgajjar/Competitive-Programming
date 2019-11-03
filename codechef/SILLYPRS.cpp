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
		ll n, val, ans=0;
		cin>>n;
		vector<ll>even_a, odd_a, even_b, odd_b;
		for(ll i=0; i<n; i++)
		{
			cin>>val;
			if(val%2==0)
				even_a.push_back(val);
			else
				odd_a.push_back(val);
		}
		for(ll i=0; i<n; i++)
		{
			cin>>val;
			if(val%2==0)
				even_b.push_back(val);
			else
				odd_b.push_back(val);
		}
		if(even_a.size()==even_b.size())
		{
			for(ll i=0; i<even_a.size(); i++)
				ans+=(even_a[i]+even_b[i])/2;
			for(ll i=0; i<odd_a.size(); i++)
				ans+=(odd_a[i]+odd_b[i])/2;
		}
		else if(even_a.size()<even_b.size())
		{
			int k=0, j=0;
			for(ll i=0; i<even_a.size(); i++)
				ans+=(even_a[i]+even_b[i])/2;
			for(ll i=even_a.size(); i<even_b.size(); i++)
				ans+=(odd_a[k]+even_b[i])/2, k++;
			for(ll i=k; i<odd_a.size(); i++)
				ans+=(odd_a[i]+odd_b[j])/2, j++;
		}
		else
		{
			int k=0, j=0;
			for(ll i=0; i<even_b.size(); i++)
				ans+=(even_a[i]+even_b[i])/2;
			for(ll i=even_b.size(); i<even_a.size(); i++)
				ans+=(odd_b[k]+even_a[i])/2, k++;
			for(ll i=k; i<odd_b.size(); i++)
				ans+=(odd_b[i]+odd_a[j])/2, j++;
		}
		cout<<ans<<endl;

	}
}