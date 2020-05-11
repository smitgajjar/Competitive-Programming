#include<bits/stdc++.h>
using namespace std;

int t, n, q, c, ans;
string s;
int m[26];

int main()
{
	// freopen("in.txt", "r", stdin);
	cin>>t;
	while(t--)
	{
		cin>>n>>q>>s;
		for(int i=0; i<26; i++) m[i]=0;
		for(char c: s)
			m[c-'a']++;
		while(q--)
		{
			ans=0;
			cin>>c;
			for(int i: m)
				if(i>c)
					ans+=(i-c);
			cout<<ans<<endl;
		}
	}
}