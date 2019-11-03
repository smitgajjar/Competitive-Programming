#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

map<pair<ll, ll>, bool>mp;
int main()
{
	int t;
	cin>>t;
	for(int T=1; T<=t; T++)
	{
		ll n, r, c, sr, sc;
		string s;
		cin>>n>>r>>c>>sr>>sc>>s;
		mp.clear();

		mp[{sr, sc}]=1;
		ll cr=sr, cc=sc;
		for(auto i: s)
		{
			switch(i)
			{
				case 'N':
				cr-=1;
					while(1)
					{
						
						if(mp.find({cr, cc})==mp.end())
						{
							mp[{cr, cc}]=1;
							break;
						}
						else
						{
							cr-=1;
						}
					}
				break;
				case 'S':
					cr+=1;
					while(1)
					{
						
						if(mp.find({cr, cc})==mp.end())
						{
							mp[{cr, cc}]=1;
							break;
						}
						else
						{
							cr+=1;
						}
					}
				break;
				case 'E':
				cc+=1;
					while(1)
					{
						
						if(mp.find({cr, cc})==mp.end())
						{
							mp[{cr, cc}]=1;
							break;
						}
						else
						{
							cc+=1;
						}
					}
				break;
				case 'W':
				cc-=1;
					while(1)
					{
						
						if(mp.find({cr, cc})==mp.end())
						{
							mp[{cr, cc}]=1;
							break;
						}
						else
						{
							cc-=1;
						}
					}
				break;
			}
		}

		cout<<"Case #"<<T<<": ";
		cout<<cr<<' '<<cc<<endl;
	}
}