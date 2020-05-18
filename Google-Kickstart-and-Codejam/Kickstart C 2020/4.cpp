#include<bits/stdc++.h>
#define int long long
using namespace std;

int t, n, q, a[200001], l ,r, sweet, co, ans;
char tmp;

void solve()
{
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>a[i];
	ans=0;
	for(int i=0; i<q; i++) {
		cin>>tmp>>l>>r;
		if(tmp=='Q')
		{
			sweet=0;
			co=1;
			for(int i=l; i<=r; i++)
			{
				sweet+=co*a[i];
				if(co>0)
					co++;
				else
					co--;
				co=-co;
			}
			ans+=sweet;
		}
		else
		{
			a[l]=r;
		}

	}
}

void print_ans()
{
	cout<<ans;
}

int32_t main()
{
	// freopen("in.txt", "r", stdin);
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		solve();
		cout<<"Case #"<<tt<<": ";
		print_ans();
		cout<<endl;
	}
}
