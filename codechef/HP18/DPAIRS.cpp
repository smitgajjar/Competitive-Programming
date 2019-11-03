#include <bits/stdc++.h>
using namespace std;	

int main()
{
	long long n, m, value;
	cin>>n>>m;
	map<long long, long> a;
	map<long long, long> b;
	for(long i=0; i<n; i++)
	{
		cin>>value;
		a.insert({value, i});
	}
	for(long i=0; i<m; i++)
	{
		cin>>value;
		b.insert({value, i});
	}
	for(long i=0; i<m; i++)
	{
		cout<<a.map::begin()->second<<' '<<i<<endl;
	}
	auto x=(b.map::rbegin()->second);
	for(long i=0; i<n;i++)
	{
		if(i!=a.map::begin()->second)
			cout<<i<<' '<<x<<endl;
	}
}