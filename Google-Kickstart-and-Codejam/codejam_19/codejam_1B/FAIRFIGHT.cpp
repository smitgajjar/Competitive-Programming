//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class node
{
public:
	node *l, *r;
	ll max;
};

node* p=new node;
p.l=NULL;
p.r=NULL;
p.max=c[0];



int main()
{
	int t=1;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		ll n, k, temp, cnt=0;
		cin>>n>>k;
		vector<ll>c, d;
		for(ll i=0; i<n; i++)
		{
			cin>>temp;
			c.push_back(temp);
		}
		for(ll i=0; i<n; i++)
		{
			cin>>temp;
			d.push_back(temp);
		}



		cout<<"Case #"<<tt<<": "<<cnt<<endl;
	}
}