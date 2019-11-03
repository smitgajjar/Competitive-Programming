#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		int a, b, l_bob=0, l_alice=0;
		cin>>n>>a>>b;
		long long value;
		for(long i=0; i<n; i++)
		{
			cin>>value;
			if(!(value%a))
				l_bob++;
			else if(!(value%b))
				l_alice++;
		}
		if(l_bob>l_alice)
			cout<<"BOB\n";
		else
			cout<<"ALICE\n";

	}
}