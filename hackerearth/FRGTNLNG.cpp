#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, k, l;
		cin>>n>>k;
		vector<pair<string, bool>>s;
		string temp;
		for(int i=0; i<n; i++)
			cin>>temp, s.push_back({temp, false});
		while(k--)
		{
			cin>>l;
			set<string>st;
			while(l--)
				cin>>temp, st.insert(temp);
			for(int i=0; i<n; i++)
				if(st.find(s[i].first)!=st.end())
					 s[i].second=true;
		}
		for(int i=0; i<n; i++)
			cout<<(s[i].second?"YES ":"NO ");
		cout<<endl;
	}
}