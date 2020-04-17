#include<bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k,ans;
int a[100001], minuss[100001], pluss[100001];
int32_t main()
{
	cin>>t;
	while(t--)
	{
		ans=LLONG_MAX;
		cin>>n>>k;
		for(int i=0; i<n ;i++)
		{
			cin>>a[i];
		}
		for(int i=0; i<n ;i++)
		{
			minuss[i]=a[i]%k;
			if(minuss[i]%k==0)
				pluss[i]=0;
			else
				pluss[i]=k-minuss[i];
		}
		for(int i=1; i<n ;i++)
		{
			minuss[i]+=minuss[i-1];
		}
		for(int i=n-2; i>=0 ;i--)
		{
			pluss[i]+=pluss[i+1];
		}
		for(int i=1; i<n ;i++)
		{
			if((minuss[i-1]-pluss[i])>=0)
				ans=min(ans, minuss[i-1]-pluss[i]);
		}
		ans=min(ans, minuss[n-1]);
		cout<<ans<<endl;
	}
}