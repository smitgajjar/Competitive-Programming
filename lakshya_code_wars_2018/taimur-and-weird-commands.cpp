#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000000+7)
struct triplet{
	long type, l, r, flag;
};

int main()
{
	long t;
	cin>>t;
	while(t--)
	{
		long n, m;
		cin>>n>>m;
		vector<long> a;
		a.assign(n, 0);
		vector<triplet> cmd;
		cmd.clear();	 
		long p=1;
		for(long i=0; i<m; i++)
		{
			long typ, left, right;
			cin>>typ>>left>>right;
			int flag=1;
			if(typ==1 && right>n)
				right=n;
			if(typ=1 && right>n && left>n)
				left=0, right=0, flag=0;
			cmd.push_back({typ, left, right, flag});
		}
		map<long, vector<long>>v;
		v.clear();
		for(long i=0; i<m; i++)
		{
			if(!cmd[i].flag)
				continue;
			
			if(cmd[i].type==1)
			{
				//v[i].b(a.begin(), a.end());
				for(long j=(cmd[i].l-1); j<=(cmd[i].r-1); j++)
				{
					a[j]=(a[j]%MOD+1)%MOD;
					//a.pop_back();
				}
				// for(auto p: a)
				// 	cout<<p<<' '; a) a)
				// 	cout<<p
				// 	cout<<p
//				cout<<endl;
				v.insert({i, a});

			}
			else
			{
				//v[i].b(a);

				for(long j=(cmd[i].l-1); j<=(cmd[i].r-1); j++)
				{
					for(long k=0; k<n; k++)
					{
						if(j!=0) a[k]=(a[k]%MOD+((v[j][k]%MOD-v[j-1][k]%MOD)%MOD)%MOD)%MOD;
							//a.insert(a.begin()+k, a[k]+(v[j][k]-v[j-1][k])), a.pop_back(), cout<<a[k]<<'|';
						else a[k]=(a[k]%MOD+(v[j][k])%MOD)%MOD;
							//a.insert(a.begin()+k, a[k]+(v[j][k])), a.pop_back(), cout<<a[k]<<'|';
					}
				}
				v.insert({i, a});
				// cout<<endl<<endl;
				// for(auto p: a)
				// 	cout<<p<<' ';
				// cout<<endl;
				
			}
		}
		for(auto i: a)
			cout<<i<<' ';
		cout<<endl;

	}
}