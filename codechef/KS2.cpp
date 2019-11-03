#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int ds(ll n)
{
	int sum=0;
	while(n>9)
	{
		sum+=n%10;
		n/=10;
	}
	sum+=n;
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, last, dsum;
		cin>>n;
		last=0;
		dsum=ds(n);

		while(dsum%10!=0)
		{
			dsum++;
			last++;
		}
		cout<<n<<last<<endl;

	}
}