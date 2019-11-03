//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
        string s;
        cin>>s;
        if(s.find("RWY")==string::npos && s.find("YWR")==string::npos && s.find("WRY")==string::npos && s.find("YRW")==string::npos && s.find("RYW")==string::npos && s.find("WYR")==string::npos && s.find("WR")!=0 && s.find("WY")!=0 && s.find("YR")!=0 && s.find("YW")!=0 && s.find("RY")!=0 && s.find("RW")!=0 && s.find("WR")!=(s.length()-1) && s.find("WY")!=(s.length()-1) && s.find("YR")!=(s.length()-1) && s.find("YW")!=(s.length()-1) && s.find("RY")!=(s.length()-1) && s.find("RW")!=(s.length()-1))
	       cout<<"YES\n";
        else
            cout<<"NO\n";
	}
}
