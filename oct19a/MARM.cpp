#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long k;
		cin>>n>>k;
		vector<int> a(n);

		// vector<int> b(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		// b=a;
		// for(int i=0; i<k; i++)
		// {
		// 	a[i%n]=a[i%n]^a[n-i%n-1];
		// 	cout<<a[i%n]<<' ';
		// 	// if((i+1)%n==0)
		// 	// {
		// 	// 	cout<<i<<endl;
		// 	// 	for(auto j: a)
		// 	// 		cout<<j<<' ';
		// 	// 	cout<<endl;
		// 	// }
		// }
		// cout<<endl;
		// for(int i=0; i<n; i++)
		// 	cout<<a[i]<<' ';
		// cout<<endl;
		// a=b;
		for(int i=0; i<(int)(k%(3LL*n)); i++)
		{
			a[i%n]=a[i%n]^a[n-i%n-1];
			// cout<<a[i%n]<<' ';	
			// if((i+1)%n==0)
			// {
			// 	cout<<i<<endl;
			// 	for(auto j: a)
			// 		cout<<j<<' ';
			// 	cout<<endl;
			// }
		}
		if(k > (n/2) and n%2==1)
			a[n/2]=0;
		for(int i=0; i<n; i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}