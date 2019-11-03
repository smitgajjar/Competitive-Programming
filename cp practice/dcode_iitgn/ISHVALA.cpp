#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, x, y, s, tp;
		cin>>n>>m;
		cin>>x>>y>>s;
		vector<int> xa, ya;
		xa.push_back(0);
		ya.push_back(0);

		for(int i=0; i<x; i++)
		{
			cin>>tp;
			xa.push_back(tp);
		}
		for(int i=0; i<y; i++)
		{
			cin>>tp;
			ya.push_back(tp);
		}
		xa.push_back(n+1);
		ya.push_back(m+1);
		int ans=0;
		for(int i=1; i<xa.size(); i++)
		{
			for(int j=1; j<ya.size(); j++)
			{
				if((xa[i]-xa[i-1]-1)>0 and (ya[j]-ya[j-1]-1)>0) 
				ans+=((xa[i]-xa[i-1]-1)/s)*((ya[j]-ya[j-1]-1)/s);
				// cout<<((xa[i]-xa[i-1]-1))<<'*'<<((ya[j]-ya[j-1]-1))<<' ';
			}
		}
		cout<<ans<<endl;



	}
}
