#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[100001];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		cin>>n;
		int dp[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		if(a[n-1]>0)
			dp[n-1]=1;
		else
			dp[n-1]=-1;

		for(int i=n-2; i>=0; i--)
		{
			if((dp[i+1]>0 and a[i]<0) or (dp[i+1]<0 and a[i]>0))
			{
				dp[i]=abs(dp[i+1])+1;
				if(a[i]<0)
					dp[i]=-dp[i];
			}
			else
			{
				if(a[i]>0)
					dp[i]=1;
				else
					dp[i]=-1;
			}
		}
		for(auto i: dp)
			cout<<abs(i)<<' ';
	}

}