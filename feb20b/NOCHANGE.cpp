#include<bits/stdc++.h>
using namespace std;
#define int long long

int t, n, p, deno[1001], out[1001],ans, idx;
bool flag;
int32_t main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		// idx=-1;
		// flag=1;
		for(int i=0; i<n; i++)
		{
			cin>>deno[i];
			// if(flag && p%deno[i])
			// {
			// 	ans=ceil((double)p/deno[i]);
			// 	idx=i;
			// 	flag=0;
			// }
			out[i]=0;
		}
		// if(idx==-1)
		// {
			int j;
			for(j=n-1; j>=0; j--)
			{
				if(p%deno[j]==0)
				{
					out[j]=(p/deno[j]-1);
					p=p-out[j]*deno[j];
				}
				else
				{
					break;
				}
			}
			if(j==-1)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<" ";
				for(int i=0; i<j; i++)
				{
					cout<<0<<" ";
				}
				cout<<p/deno[j]+1<<" ";
				for(int i=j+1; i<n; i++)
					cout<<out[i]<<" ";
				cout<<endl;
			}
		// }
		// else
		// {
		// 	cout<<"YES"<<" ";
		// 	for(int i=0; i<n; i++)
		// 	{
		// 		if(i==idx)
		// 			cout<<ans<<" ";
		// 		else
		// 			cout<<0<<" ";
		// 	}
		// 	cout<<endl;
		// }
	}
}