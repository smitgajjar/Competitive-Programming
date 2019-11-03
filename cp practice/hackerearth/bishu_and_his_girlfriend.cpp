#include<bits/stdc++.h>
using namespace std;

int ans=0;


void bfs(int v, vector<vector<int>> adj, int n, unordered_map<int, int> m)
{
	vector<bool> vis(n+1);
	queue<int> q;
	q.push(v);
	vis[v]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i: adj[u])
		{
			if(!vis[i])
			{
				vis[i]=1;//cout<<i<<' ';
				q.push(i);
				if(m[i] and ans==0)
				{
					ans=i;
				}
			}
		}
	}

}
int main()
{
	int n, u, v, q;
	cin>>n;
	vector<vector<int>> adj(n+1);
	unordered_map<int, int> m;
	for(int i=0; i<n-1; i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin>>q;
	for(int i=0; i<q; i++)
	{
		cin>>u;
		m[u]=1;
	}
	bfs(1, adj, n, m);
	cout<<ans;
}