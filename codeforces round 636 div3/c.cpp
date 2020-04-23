#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[200001];
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int mx;
		int sum=0;
		bool pos;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			if(i==0)
			{
				mx=a[i];
				if(mx>0) pos=1;
				else pos=0;
			}
			else
			{
				if(a[i]>0)
				{
					if(pos)
					{
						mx=max(mx, a[i]);
					}
					else
					{
						sum+=mx;
						mx=a[i];
					}
					pos=1;
				}
				else
				{
					if(!pos)
					{
						mx=max(mx, a[i]);
					}
					else
					{
						sum+=mx;
						mx=a[i];
					}
					pos=0;
				}
			}
			
		}
		sum+=mx;
		cout<<sum<<endl;
	}
}