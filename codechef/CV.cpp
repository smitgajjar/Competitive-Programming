#include<bits/stdc++.h>
using namespace std;

bool fun(char i, char j)
{
	if(!(i=='a' || i=='e' || i=='i' || i=='o' || i=='u') and ((j=='a' || j=='e' || j=='i' || j=='o' || j=='u')) )
		return true;
	else
		return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int l=0, cnt=0;
		for(auto i=s.begin(); i!=s.end(); i++)
		{
			if(i!=s.begin())
			{
				cnt+=fun(*prev(i, 1), *i);
			}
		}
		cout<<cnt<<endl;
	}
}