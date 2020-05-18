#include<bits/stdc++.h>
#define int long long
using namespace std;

int t, n, k, a[200001], ptr, ans, flag;

void solve()
{
	cin>>n>>k;
	ptr=k;
	ans=0;
	flag=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==ptr)
		{
			ptr--;
			if(ptr==0)
			{
				ans++;
				ptr=k;
			}
		}
		else if(a[i]==k)
		{
			ptr=k;
			ptr--;
			if(ptr==0)
			{
				ans++;
				ptr=k;
			}
		}
		else
		{
			ptr=k;
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
