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
		ll a[n], b[n], sa[n], sb[n], sum=0;
		for(ll i=0; i<n; i++)
		    cin>>a[i]>>b[i];
		 sa[n-1]=a[n-1];
		 sb[n-1]=b[n-1];
		for(ll i=n-2; i>=0; i--)
		{
		    sa[i]=sa[i+1]+a[i];
		    sb[i]=sb[i+1]+b[i];
		}
		for(ll i=0; i<n; i++)
		{
		    if(sa[i]<sb[i])
		    {
		        sum+=sb[i];
		        break;
		    }
		    sum+=a[i];
		}
		cout<<sum<endl;
		
	}
}
