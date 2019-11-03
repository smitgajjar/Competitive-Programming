#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int n, m, a, b, q;
	cin>>n>>m;
	vector<int>v[n+1];

	for(int i=0; i<m; i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		if(find(v[a].begin(), v[a].end(), b)!=v[a].end() or find(v[b].begin(), v[b].end(), a)!=v[b].end())
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;	
	}

}
