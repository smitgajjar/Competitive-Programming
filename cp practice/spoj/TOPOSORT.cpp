#include<bits/stdc++.h>
using namespace std;
const int N=100001;

int indeg[N];

//N vertices
vector<int> g[N];

// n = given number of vertices
int n, m, u, v;

// topological order, which stores lexicographically
vector<int> order;

//Returns 0 if a cycle is found
bool topSort()
{

	// Min heap for having lexicographically sorted elements
	// in the topological ordering of nodes
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=n; i++)
	{
		// for every neighbour it of i, i.e. outdegree for i and indegree for it
		for(auto it: g[i])
			indeg[it]++;
	}
	for(int i=1; i<=n; i++)
	{
		if(!indeg[i])
			pq.push(i);
	}
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		order.push_back(u);
		for(auto v: g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				pq.push(v);
		}
	}
	// if all nodes are not stored, there must be a cycle
	if(order.size()!=n)
		return false;
	return true;
}

int main()
{
	// freopen("in.txt", "r", stdin);
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}
	if(topSort())
		for(auto i: order) cout<<i<<' ';
	else
		cout<<"Sandro fails.";
}