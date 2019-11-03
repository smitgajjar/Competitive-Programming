//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	int t=1;
	//cin>>t;
	while(t--)
	{
		ll n;
		string s;
		cin>>n>>s;
		int mp[10]={0};
		for(int i=1; i<=9; i++)
		{
			cin>>mp[i];
		}
		bool flag=0;
		for(char &c: s)
		{
			int num=c-48;
			if(num<mp[num])
			{
				c=mp[num]+48;
				flag=1;
			}
			else if(num==mp[num])
				c=mp[num]+48;
			else if(flag==1)
				break;
		}
		cout<<s<<endl;
	}
}
