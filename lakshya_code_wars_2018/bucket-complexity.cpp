#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, f_ans;
		long double ans;
		cin>>n;
		ans=(-1+sqrt(1+8*n))/2;
		f_ans=(int)ans;
		if((n-(f_ans*(f_ans+1)/2))>=1)
			f_ans++;
		cout<<f_ans<<endl;
	}
}