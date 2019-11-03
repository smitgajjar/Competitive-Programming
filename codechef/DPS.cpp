#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ch[26]={0}; 
		for(auto i: s)
		{
			ch[i-'a']++;
		}
		int cnt=0;
		for(auto c: ch)
		{
			if(c%2)
				cnt++;
		}
		//cout<<cnt<<endl;
		if(s.length()%2)
			cout<<((cnt<=3 && cnt>=1)?"DPS":"!DPS")<<endl;
		else
			cout<<((cnt==2 || cnt==1)?"DPS":"!DPS")<<endl;
	}
}