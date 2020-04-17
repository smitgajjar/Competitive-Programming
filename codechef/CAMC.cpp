#include<bits/stdc++.h>
using namespace std;

class myclass
{
public:
	int idx, value, color;
};
bool comp(myclass &a, myclass &b)
{
	return a.value<b.value;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, color=0, temp;
		cin>>n>>m;
		vector<myclass> a(n);
		set<int> s;
		// map<int, pair<int, int>> mp;
		vector<int> freq(m, 0);
		for(int i=0; i<n; i++)
		{
			cin>>temp;
			a[i]={i, temp, color++};
			if(color==m)
				color=0;
		}

		sort(a.begin(), a.end(), comp);
		int i=0, j=0, minn=INT_MAX;
		
		while(j<n or s.size()==m)
		{
			if(s.size()!=m)
			{
				s.insert(a[j].color);
				freq[a[j].color]++;
				j++;
			}
			else
			{
				// cout<<"hi";
				minn=min(minn, a[j-1].value-a[i].value);
				freq[a[i].color]--;
				
				if(freq[a[i].color]==0)
					s.erase(a[i].color);
				i++;
			}
			// for(auto k: s)
			// 	cout<<k<<' ';
			// cout<<endl;
			// cout<<s.size()<<" size"<<endl;
		}
		cout<<minn<<endl;

	}
}