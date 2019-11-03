//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class my
{
public:
	ll s, e, l;
};

bool compare(my a, my b)
{
	bool flag1=0, flag2=0, flag3=0;
	if(a.l==b.l)
		flag1=1;
	if(a.e==b.e)
		flag2=1;
	if(a.s==b.s)
		flag3=1;
	if(!flag3)
		return (a.e*a.l>b.e*b.l);
	else
		return (a.s<b.s);

}

ll solve()
{
	
	
}

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		int n;
		cin>>n;
		ll s, e, l, time=0, ans=0;
		vector<my>v;
		for(int i=0; i<n; i++)
		{
			cin>>s>>e>>l;
			v.push_back({s, e, l});
		}
		sort(v.begin(), v.end(), compare);
		for(auto i: v)
		{
			cout<<i.s<<" "<<i.e<<" "<<i.l<<endl;
			ll rem_energy=i.e-i.l*time;
			if(rem_energy>0)
				ans+=rem_energy;
			time+=i.s;
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
}
