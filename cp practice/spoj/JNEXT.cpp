#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll num;
		cin>>num;
		vector<int>a(num);
		for(ll i=0; i<num; i++)
		{
			cin>>a[i];
		}
		ll idx=-1, i;
		for(i=num-1; i>0; i--)
		{
			if(a[i-1]<a[i])
			{
				idx=i-1;
				break;
			}
		}
		if(idx==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		ll minv=a[idx], idx2;
		for(i=num-1; i>idx; i--)
		{
			if(a[i]>minv)
			{
				idx2=i;
				break;
			}
		}
		swap(a[idx], a[idx2]);
		reverse(a.begin()+idx+1, a.end());
		
		for(i=0; i<num; i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
}