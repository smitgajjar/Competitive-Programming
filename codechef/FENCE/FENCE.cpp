#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	ll n, m, k, fnc=0, a, b;
    	cin>>n>>m>>k;
    	map<pair<ll, ll>, bool>mp;
    	for(ll i=0; i<k; i++)
    	{
    	    cin>>a>>b;
    	    mp[{a, b}]=1;
    	}
    	for(auto i: mp)
    	{
    	    if(i.first.first==1)
    	        fnc++;
    	    if(i.first.first==n)
    	        fnc++;
    	    if(i.first.second==1)
    	        fnc++;
    	    if(i.first.second==m)
    	        fnc++;
    	        
    	    if(i.first.first!=1 && mp.find({i.first.first-1, i.first.second})==mp.end())
    	        fnc++;
    	    if(i.first.second!=1 && mp.find({i.first.first, i.first.second-1})==mp.end())
    	        fnc++;
    	    if(i.first.first!=n && mp.find({i.first.first+1, i.first.second})==mp.end())
    	        fnc++;
    	    if(i.first.second!=m && mp.find({i.first.first, i.first.second+1})==mp.end())
    	        fnc++;
    	}
    	cout<<fnc<<endl;
	}
	return 0;
}
