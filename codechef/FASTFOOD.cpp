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
		ll n;
		cin>>n;
		ll a[n], b[n], pa[n], sb[n], ans=0, sum=0;
		for(ll i=0; i<n; i++)
		    cin>>a[i];
		for(ll i=0; i<n; i++)
		    cin>>b[i];
		pa[0]=a[0];
		for(ll i=1; i<n; i++)
			pa[i]=pa[i-1]+a[i];
		sb[n-1]=b[n-1];
		for(ll i=n-2; i>=0; i--)
		    sb[i]=sb[i+1]+b[i];
		ans=max(pa[n-1], sb[0]);
		for(ll i=1; i<n; i++)
			sum=pa[i-1]+sb[i],ans=max(ans, sum);
		cout<<ans<<endl;
		
	}
}
