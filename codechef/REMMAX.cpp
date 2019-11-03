#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
		if(n.length()==1)
			cout<<n;
		else
		{
			if(n[0]!='1')
			{
				int a=n[0]-'0'-1;
				cout<<a;
			}
			for(int i=1; i<n.length(); i++)
			{
				cout<<9;
			}
		}
		cout<<endl;
	}
}