#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, val;
		cin>>n;
		vector<ll>a;
		for(ll i=0; i<n; i++)
		{
			// cout<<"h";
			cin>>val;
			a.push_back(val);
		}

		// cout<<"e";
		
		ll temp=n-1;
		ll sum=0, localS=0;
		// continue;
		while(temp--)
		{
			// cout<<temp;

			// ll sum=0, localS=0;
			// cout<<"a";

			ll minV=*a.begin()+*(prev(a.end(), 1));
			
			// cout<<"b";
			
			auto minI=prev(a.end(),1);
			
			// cout<<"c";
			
			for(auto it=a.begin(); it!=prev(a.end(), 1); it++)
			{
				// cout<<"d";
				localS=*it+*next(it, 1);
				if(localS<minV)
				{
					minV=localS;
					minI=it;
				}
			}
			// cout<<"e";	
			if(minI==prev(a.end(), 1))
			{
				// break;
				a.erase(a.begin());
			
				// break;
				a.erase(a.begin()+a.size()-1);
				a.insert(a.begin(), minV);
			}
			else
			{
				a.erase(minI, minI+2);
				a.insert(minI, minV);
			}
			// for(auto i: a)
			// 	cout<<i<<' ';
			// cout<<endl;
			// cout<<sum<<endl;
			sum+=minV;
			cout<<"a"<<minV<<endl<<endl;
		}
		cout<<sum<<endl;
	}
}