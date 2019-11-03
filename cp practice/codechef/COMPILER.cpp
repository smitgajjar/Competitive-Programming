#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		ll ans=0, k=1;
		bool flag=1;
		stack<char>st;
		cin>>s;
		for(char c: s)
		{
			if(c=='<')
				st.push(c);
			else
			{
				if(!st.empty())
				{
					st.pop();
					//ans+=2;
				}
				else
				{
					flag=0;
					break;
				}

			}
			if(st.empty())
			{
				ans=k;
			}
			k++;
		}
		cout<<ans<<endl;
	}
}