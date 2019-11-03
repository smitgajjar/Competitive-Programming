#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// vector<ll>hi={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

set<ll> getFactor(ll n)
{
	set<ll>prim;
	// cout<<n<<endl;
	while(n%2==0)
	{
		prim.insert(2);
		n/=2;
	}
	for (ll i=3;i<=sqrt(n); i+=2) 
	{
		while(n%i==0)
		{
			prim.insert(i),	n/=i;
		}
	}
	if(n>2) prim.insert(n);
	// for(auto i: prim)
	// 	cout<<i<<endl;	 
	return prim;
}
int main()
{
	// cout<<31623<<endl;
	int t;
	cin>>t;
	ll m, x1=400000, p=31627;
	set<ll>prime, prime2;
	std::vector<ll>inter(10);
	while(t--)
	{
		inter.assign(10, 0);
		prime.clear();
		prime2.clear();
		cout<<1<<' '<<x1<<endl;
		m=(x1*x1)%p;
		//cin>>m;

		string s;
		// if(m==0)
		// {
		// 	cout<<2<<' '<<x1<<endl;
		// 	cin>>s;
		// 	if(s=="No")
		// 		break;
		// 	continue;
		// }
	    //ll no=1000267129-m, ans=0;
	    ll no=x1*x1-m, ans=0;
	    bool wrong=0;
	    
		prime=getFactor(no);


		ll se=(*prime.rbegin());
		
		cout<<1<<' '<<se<<endl;
		m=(se*se)%p;
		//cin>>m;
		if(m==0)
		{
			cout<<2<<' '<<se<<endl;
			cin>>s;
			if(s=="No")
				break;
			continue;
		}
		no=se*se-m;
		prime2=getFactor(no);
		vector<ll>::iterator it=set_intersection(prime.begin(), prime.end(), prime2.begin(), prime2.end(), inter.begin());
		inter.resize(it-inter.begin());
		for(auto i: inter)
			cout<<i<<' ';
		cout<<endl;
		if(inter.size()==1)
		{
			cout<<2<<' '<<*inter.begin()<<endl;
			cin>>s;
			if(s=="No")
				break;
			continue;
		}
		// for(auto i: prime)
		// 	cout<<i<<' ';
		// cout<<endl<<endl;
		// for(auto i: prime2)
		// 	cout<<i<<' ';
		// cout<<endl<<endl;
		//continue;
		bool right=0;
		for(auto i=inter.rbegin(); i!=prev(inter.rend(),1); i++)
		{
			cout<<1<<' '<<*i<<endl;
			//cin>>m;
			m=((*i)*(*i))%p;
			if(m==0)
			{
				ans=*i;
				right=1;
				break;
			}
			else if(m==-1)
			{
				wrong=1;
				break;
			}
		}
		if(wrong)
			break;
		if(!right)
			cout<<2<<' '<<(*inter.begin())<<endl;
		else
			cout<<2<<' '<<ans<<endl;

		cin>>s;
		if(s=="No")
			break;
	}
}