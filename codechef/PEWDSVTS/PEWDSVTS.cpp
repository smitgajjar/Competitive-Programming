//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		ll n, a, b, x, y, z, todo;
		cin>>n>>a>>b>>x>>y>>z;
		
		ll k, val;
		
		k=ceil((z-b)/(double)y-1);
		
		todo=z-(a+k*x);

		priority_queue<ll>q;
		for(ll i=0; i<n; i++)
			cin>>val, q.push(val);
		if(todo<=0)
		{
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		while(todo>0 && !q.empty())
		{
			val=q.top();
			todo-=val;
			q.pop();
			if(val/2!=0)
				q.push(val/2);
			ans++;
		}
		if(q.empty() && todo>0)
		{
			cout<<"RIP"<<endl;
		}
		else
			cout<<ans<<endl;

	}
}