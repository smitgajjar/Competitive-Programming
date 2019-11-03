#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    string s;
	    char c;
	    cin>>n>>s>>c;
	    vector<ll>v;
	    v.push_back(-1);
	    for(ll i=0; i<n; i++)
	    {
	        if(s[i]==c)
	            v.push_back(i);
	    }
	    v.push_back(n);
	    ll ans=0;
	    for(ll k=1;k<=v.size()-1;k++)
	    {
    	    for(ll i=1; i<v.size()-k; i++)
    	    {
    	        ans+=(v[i]-v[i-1])*(v[i+k]-v[i+k-1]);
    	    }
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
