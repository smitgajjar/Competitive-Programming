#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	vector<int>a(n, 0);
	stack<int>s;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	int ans=a[0]^a[1], top1, top2;
	for(int i=0; i<n; i++)
	{
		while(!s.empty() and s.top()<a[i])
			s.pop();
		s.push(a[i]);
		if(s.size()>=2)
		{
			top1=s.top(); s.pop();
			top2=s.top(); s.push(top1);
			ans=max(ans, top1^top2);
		}
	}
	cout<<ans<<endl;


}