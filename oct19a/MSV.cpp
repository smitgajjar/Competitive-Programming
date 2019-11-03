#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n), vis(n, 0);
		for(int i=0; i<n ;i++)
			cin>>a[i];
		int ans, maxx=0;
		for(int i=n-1; i>=1; i--)
		{
			ans=0;
			if(!vis[i])
			{
				for(int j=i-1; j>=0; j--)
				{
					if(a[j]%a[i]==0)
					{
						ans++;
						vis[j]=1;
					}
				}
				if(ans>maxx)
					maxx=ans;
			}
		}
		cout<<maxx<<endl;
	}
}