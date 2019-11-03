#include<bits/stdc++.h>
#define debug(s) cout<<s<<endl<<endl;
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x, y, k;
		cin>>x>>y>>k;
		double ans=(x+y+1)*1.0/k;
		ll a=ceil(ans);
		// cout<<ans<<endl;
		if(a%2==0)
			cout<<"Paja";
		else
			cout<<"Chef";
		cout<<endl;
	}
}