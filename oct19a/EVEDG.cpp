#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, u, v, k=0;
		cin>>n>>m;
		vector<vector<int>>adj(n+1);
		for(int i=0; i<m; i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(m%2==0)
		{
			cout<<1<<endl;
			for(int i=1; i<=n; i++)
				cout<<1<<' ';
			cout<<endl;
			continue;
		}

		int sub1=-1, sub2=-1;
		for(int i=1; i<=n; i++)
		{
			if(adj[i].size()%2==1)
			{
				sub1=i;
				k++;
				break;
			}
		}
		if(sub1!=-1)
		{
			cout<<2<<endl;
			for(int i=1; i<=n; i++)
			{
				if(sub1==i)
				{
					cout<<1;
				}
				else
					cout<<2;
				cout<<' ';
			}
			cout<<endl;
			continue;
		}
		cout<<3<<endl;
		for(int i=1; i<=n; i++)
		{
			if(adj[i].size()!=0)
			{
				sub1=i;
				sub2=adj[i][0];
			}
		}
		for(int i=1; i<=n; i++)
		{
			if(sub1==i)
				cout<<1;
			else if(sub2==i)
				cout<<2;
			else
				cout<<3;
			cout<<' ';
		}
		cout<<endl;
	}
}