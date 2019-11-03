#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a, b, c, k;
		cin>>k>>a>>b>>c;
		if(k==(a+b+c) || k==(a+b-c) || k==(a-b+c) || k==(-a+b+c) || k==(-a-b+c) || k==(a-b-c) || k==(-a+b-c) || k==(-a-b-c))
			cout<<"WIN\n";
		else
			cout<<"LOSE\n";
	}
}