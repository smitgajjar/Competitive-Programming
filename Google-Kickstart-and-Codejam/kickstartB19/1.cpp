//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve()
{
	
	
}

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		ll n, nq,  ans=0;
		string s;
		map<char, ll>mp;
		vector<map<char, ll>>v;
		cin>>n>>nq>>s;
		for(ll i=0; i<n; i++)
		{
			mp[s[i]]++;
			v.push_back(mp);
		}
		while(nq--)
		{
			ll a, b, occur, len, flag=1;
			cin>>a>>b;
			len=b-a+1;
			
			
			if(len%2==0)
			{
				for(auto i: v[b-1])
				{
					if(a!=1)
						occur=i.second-v[a-2][i.first];
					else
						occur=i.second;
					if(occur%2!=0)
					{
						flag=0;
						break;
					}
				}
				if(flag)
					ans++;
			}
			else
			{
				vector<ll>occ;
				for(auto i: v[b-1])
				{
					if(a!=1)
						occur=i.second-v[a-2][i.first];
					else
						occur=i.second;
					occ.push_back(occur);
				}

				ll odd=0;
				for(auto i: occ)
				{
					if(i%2!=0)
						odd++;
				}
				if(odd==1)
					ans++;
			}
			
			
			
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
}
