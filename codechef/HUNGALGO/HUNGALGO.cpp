//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		int n;
		cin>>n;
		int a[n][n];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>a[i][j];
			}
		}
		bool flag, ans=1;
		for(int i=0; i<n; i++)
		{
			flag=0;
			for(int j=0; j<n; j++)
			{
				if(a[i][j]==0)
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				ans=0;
				break;
			}

		}
		if(!ans)
		{
			cout<<"NO\n";
			continue;
		}
		else
		{
			for(int i=0; i<n; i++)
			{	
				flag=0;
				for(int j=0; j<n; j++)
				{
					if(a[j][i]==0)
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					ans=0;
					break;
				}

			}

		}
		if(!ans)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
}
