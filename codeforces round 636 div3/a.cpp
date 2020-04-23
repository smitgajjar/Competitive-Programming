#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=3LL;
		while(ans<=1000000000LL)
		{
			if(n%ans==0)
			{
				cout<<(n/ans);
				break;
			}
			ans=((ans+1LL)<<1LL)-1LL;
		}
		cout<<endl;
	}
}