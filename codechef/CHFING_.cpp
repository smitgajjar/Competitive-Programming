#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		if(n==2)
			cout<<(((((k-1)*(k-1))%mod+(k-1))%mod)/2)%mod<<endl;
		else
			cout<<0<<endl;
	}
}