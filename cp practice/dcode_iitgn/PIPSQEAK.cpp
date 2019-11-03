#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, h, y1, y2, l, type, x, ans=0;
		bool flag=1;
		cin>>n>>h>>y1>>y2>>l;
		for(int i=0; i<n; i++)
		{
			cin>>type>>x;
			if(flag)
			{
				if(type==1)
				{
					if((h-y1)<=x)
						ans++;
					else if(l!=1)
					{
						ans++;
						l--;
					}
					else if(l==1)
					{
						flag=0;
					}
				}
				else
				{
					if((y2)>=x)
						ans++;
					else if(l!=1)
					{
						ans++;
						l--;
					}
					else if(l==1)
					{
						flag=0;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}