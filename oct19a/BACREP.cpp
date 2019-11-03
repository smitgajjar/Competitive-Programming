#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int idx;
	vector<pair<int, int>> info;
	vector<node*>child;

};

node* newnode(int idx, int sec, int val)
{
	node * temp = new node;
	temp->idx=idx;
	(temp->info).push_back({sec, val});
	return temp;
}

void dfs(int u, vector<vector<int>> adj, vector<bool> vis, vector<int>& parent)
{
	if(!vis[u])
	{
		vis[u]=1;
	}
	for(auto i: adj[u])
	{
		if(!vis[i])
		{
			parent[i]=u;
			dfs(i, adj, vis, parent);
		}
	}

}
int main()
{
	int t=1;
	// cin>>t;
	while(t--)
	{
		int n, q, u, v;
		cin>>n>>q;
		vector<vector<int>> adj(n+1);
		vector<int> value(n+1);
		for(int i=0;i<n-1; i++)
		{
			cin>>u>>v;
			if(v!=1)
				adj[u].push_back(v);
			if(u!=1)
				adj[v]. push_back(u);
		}
		for(int i=1;i<=n; i++)
		{
			cin>>value[i];
		}
		
		
		
		
		vector<bool> vis(n+1, 0);
		vector<int> parent(n+1);
		dfs(1, adj, vis, parent);
		// for(int i: parent)
		// 	cout<<i<<endl;
		// for(int i=2;i<=n; i++)
		// {
		// 	value[i]=value[parent[i]];
		// }
		// value[1]=0;

		char c;
		for(int i=0;i<q; i++)
		{

			cin>>c;
			if(c=='+')
			{
				for(int j=n;j>=2; j--)
				{
					value[j]+=value[parent[j]];
					value[parent[j]]=0;
				}
				
				cin>>u>>v;
				value[u]+=v;
				
			}
			else
			{x
				for(int j=n;j>=2; j--)
				{
					value[j]+=value[parent[j]];
					value[parent[j]]=0;
				}
				cin>>u;
				cout<<value[u]<<endl;
				
			}
			for(int i: value)
				cout<<i<<endl;

		}







		// stack<int> s;
		
		// vector<bool> vis(n+1);
		// s.push(1);
		// vis[1]=1;
		
		// node *root = newnode(1, 0, value[1]);

		// while(!s.empty())
		// {
		// 	int node=s.top();
		// 	s.pop();

		// 	if(!vis[node])
		// 	{
		// 		vis[node]=1;
		// 		cout<<node<<endl;
		// 		while((root->child).size()!=0)
		// 		{
		// 			root=root->child[0];
		// 		}
		// 		(root->child).push_back(newnode(node, 0, value[node]));
		// 	}


		// 	for(auto i: adj[node])
		// 	{
		// 		if(!vis[i])
		// 		{
		// 			vis[i]=1;
		// 			s.push(i);
		// 			// cout<<i<<endl;
		// 			// while((root->child).size()!=0)
		// 			// 	temp=temp->child;
		// 			// (root->child).push_back(newnode(i, 0, value[i]));
		// 		}
		// 	}
		// }

		

		

	}
}