#include<bits/stdc++.h>
using namespace std;

int n, q, t, x1, x2, h, p, qq, cnt;
int a[100001];
int main()
{
	cin>>t;
	while(t--) 
	{
		cin>>n>>q;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		while(q--)
		{
			cin>>x1>>x2>>h;
			x1--, x2--;
			cnt=0;
			for(int i=x1; i<x2; i++)
			{
				if(a[i]<a[i+1])
				{
					if(a[i]<=h and h<=a[i+1])
					{
						cnt++;
					}
				}
				else
				{
					if(a[i+1]<=h and h<=a[i])
					{
						cnt++;
					}	
				}
			}
			cout<<cnt<<endl;
		}
	}
}