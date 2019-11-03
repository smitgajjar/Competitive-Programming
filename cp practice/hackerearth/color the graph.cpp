#include <bits/stdc++.h>
using namespace std;
const int N=100001;

vector<int> g[N];
bool vis[N];
bool color[N];
bool flag=1;
int sz, red;

void dfs(int s)
{
	vis[s]=1;
	sz++;
	for(auto i: g[s])
	{
		if(!vis[i])
		{
			color[i]=!color[s];
			if(color[i]) red++;
			dfs(i);
		}
		else if(color[i]==color[s])
		{
			flag=0;
			return;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		flag=1;
		int n, m, u, v;
		cin>>n>>m;
		memset(vis, 0, sizeof vis);
		memset(color, 0, sizeof color);
		for(int i=1; i<=n; i++)
			g[i].clear();
		for(int i=0; i<m; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				red=0;
				sz=0;
				dfs(i);
				ans+=max(red, sz-red);				
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<ans<<endl;
		else
		{
			cout<<"NO"<<endl;
		}
	}

}