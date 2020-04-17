#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t=1;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
	cin>>t;
	while(t--)
	{
		string s;
		stack<int>st;
		cin>>s;
		map<char, int>m;
		m['x']=2;
		m['y']=4;
		m['z']=10;
		for(char c: s)
		{
			if(c=='(')
				st.push(c);
			else if(c==')')
			{
				int temp1=0, temp2=0;
				while(1)
				{
					temp1=st.top();
					st.pop();
					if(st.top()!='(')
					{
						temp2=st.top();
						st.pop();
						st.push(temp1+temp2);
					}
					else
					{
						st.pop();
						st.push(temp1);
						break;
					}
				}
			}
			else if(c>='2' and c<='9')
			{
				int temp=st.top()*(c-'0');
				st.pop();
				st.push(temp);
			}
			else
				st.push(m[c]);
		}
		int ans=0;
		while(!st.empty())
		{
			ans+=st.top();
			st.pop();
		}
		cout<<ans<<endl;
	}
}