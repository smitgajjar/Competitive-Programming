#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<string, pair<int, int>>mp;
		int val=0;
		while(val<12)
		{
			int gA, gB;
			string tA, tB, vs;
			cin>>tA>>gA>>vs>>gB>>tB;
			if(gA>gB)
				mp[tA].first+=3;
			else if(gA<gB)
				mp[tB].first+=3;
			else
				mp[tA].first++, mp[tB].first++;
			mp[tA].second+=(gA-gB), mp[tB].second+=(gB-gA);
			val++;
		}
		pair<int, int>ans, ans2;
		ans.first=INT_MIN, ans.second=INT_MIN;
		string w_team;
		for(auto i: mp)
		{
			if(i.second>ans)
				ans=i.second, w_team=i.first;
			// cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<endl;
		}
		ans2.first=INT_MIN, ans2.second=INT_MIN;
		string w_team2;
		for(auto i: mp)
		{
			if(i.second>ans2 && i.first!=w_team)
				ans2=i.second, w_team2=i.first;
			// cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<endl;
		}
		cout<<w_team<<' '<<w_team2<<endl;
		


	}
	

}