#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<ll>a(n);
		map<ll, bool>m;
		for(int i=0; i<n; i++)
			cin>>a[i];
		int id1=-1, id2=-1;
		bool flag=1;
		for(int i=0; i<n; i++)
		{
			if(id1==-1)
			{
				if(m[a[i]]==0)
					m[a[i]]=1;
				else
				{
					id1=i;
					break;
				}
			}
		}
		m.clear();
		for(int j=n-1; j>=0; j--)
		{
			if(id2==-1)
			{
				if(m[a[j]]==0)
					m[a[j]]=1;
				else
				{
					id2=j;
					break;
				}
			}
		}
		
		if(id1!=-1 and id2!=-1)
			cout<<abs(id2-id1)+1<<endl;
		else
			cout<<0<<endl;

	}
}