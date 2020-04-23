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
		if((n/2)&1 == 1)
		{
			cout<<"NO";
		}
		else
		{
			cout<<"YES"<<endl;
			int sum=0, next_sum=0;
			for(int i=2; i<=n; i+=2)
			{
				cout<<i<<' ';
				sum+=i;
			}
			for(int i=1; i<=n-1; i+=2)
			{
				if(i==n-1)
				{
					cout<<sum-next_sum<<' ';
				}
				else
				{
					next_sum+=i;
					cout<<i<<' ';
				}
			}
		}
		cout<<endl;
	}
}