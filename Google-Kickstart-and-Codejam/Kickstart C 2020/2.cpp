#include<bits/stdc++.h>
#define int long long
using namespace std;

int t, a[100001], sum, root, cnt, n, pre[100001];

void solve()
{
	cin>>n;
	cnt=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i==0)
			pre[i]=a[i];
		else
			pre[i]=pre[i-1]+a[i];
	}
	for(int i=0; i<n; i++) {
		sum=pre[i];
		root=sqrt(sum);
		if(root*root==sum)
			cnt++;
		for(int j=i+1; j<n; j++) {
			
			sum=(pre[j]-pre[i]);
			root=sqrt(sum);
			if(root*root==sum)
				cnt++;
		}
	}
}

void print_ans()
{
	cout<<cnt;
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
