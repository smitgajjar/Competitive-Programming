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
		ll n, m, pro=0;
		cin>>n>>m;
		ll c[m], d[n], f[n], b[n];
		for(ll i=0; i<m; i++)
		{
			cin>>c[i];
		}
		

		for(ll i=0; i<n; i++)
		{
			cin>>d[i]>>f[i]>>b[i];
			d[i]--;
		}
		
		for(ll i=0; i<n; i++)
		{
			if(c[d[i]]!=0)
			{
				pro+=f[i];
				c[d[i]]--;
			}
			else
			{
				pro+=b[i];
			}
		}
		cout<<pro<<endl;

	}
}