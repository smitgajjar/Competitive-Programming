//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t=1;
	cin>>t;
	while(t--)
	{
		ll n, x=0, sum=0;
		cin>>n;
		ll a[n], b[n];
		int ans[9]={0};
		for(ll i=0; i<n; i++)
		    cin>>a[i], b[i]=a[i];
		map<bool, ll>mp;
		for(int i=0; i<9; i++)
		{
			mp.clear();
			for(ll j=0; j<n; j++)
		    {
		    	mp[a[j]%2]++;
		    	a[j]/=2;
		    }
		    if(mp[1]>mp[0])
		    	ans[i]=1;
		}
		for(int i=0; i<9; i++)
		{
			x+=ans[i]*pow(2, i);
		}
		for(ll i=0; i<n; i++)
		{
			sum+=b[i]^x;
		}
		cout<<sum<<endl;

	}
}
