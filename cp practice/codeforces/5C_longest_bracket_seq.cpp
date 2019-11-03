#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	string ss;
	cin>>ss;
	stack<int>s;
	int ans=0, maxi=0, cnt=1;
	s.push(-1);
	for(int i=0; i<ss.size(); i++)
	{
		if(ss[i]=='(')
			s.push(i);
		else
		{
			s.pop();
			if(s.empty())
				s.push(i);
			else
			{
				ans=i-s.top();
				if(ans>maxi)
				{
					maxi=ans;
					cnt=1;
				}
				else if(ans==maxi)
				{
					cnt++;
				}
			}
		}
	}
	cout<<maxi<<' '<<cnt;
		
}