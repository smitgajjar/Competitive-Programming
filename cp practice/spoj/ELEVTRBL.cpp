#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int f, s, g, u, d;
	cin>>f>>s>>g>>u>>d;
	//vector<vector<int>> adj(f+1);
	vector<int>	vis(f+1, 0);

	//adj[s].push_back(s+u);
	// int j=s+u;
	queue<int> q;
	q.push(s);
	vis[s]=1;
	bool flag=1, yes=0;
	int level=0;
	if(s==g)
	{
		cout<<0<<endl;
		return 0;
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();

		if(node+u<=f and !vis[node+u])
		{
			q.push(node+u);
			vis[node+u]=1;
			level++;
			flag=0;
			if(q.back()==g)
			{
				yes=1;
				break;
			}
		}
		if(node-d>=1 and !vis[node-d])
		{
			q.push(node-d);
			vis[node-d]=1;
			if(flag)
				level++;
			flag=1;
			if(q.back()==g)
			{
				yes=1;
				break;
			}
		}
	}
	if(yes)
		cout<<level<<endl;
	else
		cout<<"use the stairs"<<endl;
}