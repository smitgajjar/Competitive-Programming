#include<bits/stdc++.h>
using namespace std;

int a[8], n;
int main()
{
	// freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		int sum=0, best=9, worst=0;
		for(int i=1; i<n; i++)
		{
			if(abs(a[i]-a[i-1])<3)
			{
				sum++;
			}
			else
			{
				best=min(sum, best);
				worst=max(sum, worst);
				sum=0;
			}
		}
		best=min(sum, best);
		worst=max(sum, worst);
		best++, worst++;
		cout<<best<<' '<<worst<<endl;
	}
}