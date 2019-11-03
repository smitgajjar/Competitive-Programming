#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0);
int priority(char c)
{
	string s="+-*/^";
	for(int i=0; i<6; i++)
	{
		if(c==s[i])
			return i;
	}
}

int main()
{
	fast
	int t;	
	cin>>t;
	while(t--)
	{
		string s, rp;
		stack<char>st;
		cin>>s;
		for(char c: s)
		{
			if(c>='a' and c<='z')
			{
				rp+=c;
			}
			else
			{

				if(c=='(')
				{
					st.push(c);
				}
				else if(c==')')
				{
					while(st.top()!='(')
					{
						rp+=st.top();
						st.pop();
					}
					st.pop();
				}
				else
				{
					if(st.top()=='(')
						st.push(c);
					else if(priority(c)<priority(st.top()))
					{
						while(!st.empty() and st.top()!='(' and priority(c)<priority(st.top()))
						{
							rp+=st.top();
							st.pop();
						}
						if(st.top()=='(')
							st.pop();
						st.push(c);
					}
					else
					{
						st.push(c);
					}

				}

			}
		}
		while(!st.empty())
		{
			rp+=st.top();
			st.pop();
		}
		cout<<rp<<endl;

	}
}