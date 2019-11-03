//Smit Gajjar
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		ll n, temp;
		cin>>n;
		cout<<"Case #"<<tt<<": ";
		if(n==4)
			{
				cout<<2<<' '<<2<<endl;continue;
			}
		temp=n;
		vector<int>v;
		while(temp!=0)
		{
			if(temp%10==4)
				v.push_back(1);
			else
				v.push_back(0);
			temp/=10;
		}
		reverse(v.begin(), v.end());
		ll a=0;
		for(int i: v)
		{
			a=a*10+i;
		}
		
		cout<<a<<' '<<n-a<<endl;
	}
}
