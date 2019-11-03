//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		int n;
		cin>>n;
		string s;
		map<char, ll>mp;
		for(int i=0; i<n; i++)
		{
			cin>>s;
			for(char c: s)
			{
				mp[c]++;
			}
		}
		ll ans=min({ mp['c']/2, mp['o'], mp['d'], mp['e']/2, mp['h'], mp['f']});
		cout<<ans<<endl;
	}
}
