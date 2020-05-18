#include<bits/stdc++.h>
#define int long long
using namespace std;

int t, r, c, arr[30][30];
vector<int> top_order;
bool isCycle, vis[26], inStack[26], graph[26][26];
unordered_map<int, int>mp;
char temp;

void dfs(int s) {
    vis[s] = true;
    inStack[s] = true;
    for(int u = 0; u < 26; u++) {
        if (graph[s][u] and vis[u] and inStack[u]) {
            isCycle=true;
        }
        if(!vis[u] and graph[s][u]) {
            dfs(u);
        }
    }
    inStack[s] = false;
    top_order.push_back(s);
}

void solve()
{
	mp.clear();
	top_order.clear();
	memset(vis, 0, sizeof vis);
	memset(inStack, 0, sizeof inStack);
	isCycle=false;
	for(int i=0; i<26; i++)
	{
		for(int j=0; j<26; j++)
		{
			graph[i][j]=0;
		}
	}
	cin>>r>>c;
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cin>>temp;
			// cin>>arr[i][j];
			arr[i][j]=temp-'A';
			mp[arr[i][j]]=1;
		}
	}
	pair<int, int> a;
	for(int i=0; i<r-1; i++)
	{
		for(int j=0; j<c; j++)
		{
			// cout<<arr[i][j]<<' '<<arr[i+1][j]<<endl;
			if(arr[i][j]!=arr[i+1][j])
			{
				graph[arr[i][j]][arr[i+1][j]]=1;
				// cout<<i<<' '<<j<<endl;
			}
		}
	}
	for(int i=0; i<26; i++)
		if(!vis[i] and mp[i])
			dfs(i);

}

void print_ans()
{
	if(isCycle)
		cout<<-1;
	else {
		for(auto i: top_order)
		{
			temp=i+'A';
			cout<<temp;
		}
	}
}

int32_t main()
{
	// freopen("in.txt", "r", stdin);
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		solve();
		cout<<"Case #"<<tt<<": ";
		print_ans();
		cout<<endl;
	}
}
