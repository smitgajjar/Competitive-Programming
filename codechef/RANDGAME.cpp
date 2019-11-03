//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isEvenPowOf2(ll n)
{
	ll k=0;
	while(n%2==0)
	{
		n/=2, k++;
	}
	return (k%2==0);
}

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		ll n;
		cin>>n;
		if(n%2==1 || )
		{
			cout<<"Win"<<endl;
		}
	}
}
