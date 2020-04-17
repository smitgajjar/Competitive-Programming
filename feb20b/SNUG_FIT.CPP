#include<bits/stdc++.h>
using namespace std;

int t, n, sum;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n], b[n];
		sum=0;
		for(int i=0; i<n ;i++)
		{
			cin>>a[i];
		}
		for(int i=0; i<n ;i++)
		{
			cin>>b[i];
		}
		sort(a, a+n);
		sort(b, b+n);
		for(int i=0; i<n ;i++)
		{
			sum+=min(a[i], b[i]);
		}
		cout<<sum<<endl;
	}
}