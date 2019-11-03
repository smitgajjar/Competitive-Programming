//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll myfunc(ll x)
{
	while(x%10==0)
	{
		x=x/10;
	}
	return x;
}
int fn(ll n)
{
	int cnt=1;
	while(n%10!=n)
	{
		n=myfunc(n+1);
		cnt++;
	}
	return(cnt+8);
}


int main()
{
	int t=1;
	//cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<fn(n)<<endl;
	}
}
