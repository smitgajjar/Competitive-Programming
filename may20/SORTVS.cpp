#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int t, n, m, req[19], curr[19], mp[19], given[19], cnt, temp, t1, t2;
vector<pair<int, int>> xy;

bool isPresent(pair<int,int> p)
{
	for(int i=0; i<m; i++)
	{
		if(xy[i]==p)
			return true;
	}
	return false;
}
int32_t main()
{
	// freopen("in.txt", "r", stdin);
	cin>>t;
	// t=1;
	while(t--)
	{
		cnt=0;
		cin>>n>>m;
		for(int i=1; i<=n; i++)
		{
			cin>>given[i];
			req[given[i]]=i;
			curr[i]=i;
			mp[i]=i;
		}
		for(int i=1; i<=m; i++)
		{
			cin>>t1>>t2;
			xy.push_back({t1, t2});
		}
		for(int i=1; i<=n; i++)
		{
			if(given[i]!=i)
			{
				if(!isPresent({i, req[i]}) and !isPresent({req[i], i}))
					cnt++;
				temp=given[i];
				given[i]=i;
				given[req[i]]=temp;
				req[temp]=req[i];
				req[i]=i;
			}
		}
		cout<<cnt<<endl;
	}
}