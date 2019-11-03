#include <bits/stdc++.h>
using namespace std;
long long main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n, k;
		cin>>n>>k;
		set<long long> r, c;
		for(long long i=1; i<=n; i++)
		{
			r.insert(i);
			c.insert(i);
		}
		long long rv, cv;
		while(k--)
		{
			cin>>rv>>cv;
			r.erase(rv);
			c.erase(cv);
		}
		cout<<(r.size())<<' ';
		for(auto i=r.begin(), j=c.begin(); i!=r.end(); i++, j++)
		{
			cout<<*i<<' '<<*j<<' ';
		}
		cout<<endl;
	}
}