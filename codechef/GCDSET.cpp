#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll l, r, g;
		cin>>l>>r>>g;
		ll ans=(r/g-(l-1)/g);
		if(ans==1)
		{
			if(l<=g and g<=r)
			{}
			else
				ans=0;
		}
		cout<<ans<<endl;
	
}}