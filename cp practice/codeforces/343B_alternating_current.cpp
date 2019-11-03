#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	string ss;
	stack<char>s;
	cin>>ss;
	for(char c: ss)
	{
		if(s.empty())
			s.push(c);
		else if(s.top()==c)
			s.pop();
		else
			s.push(c);
	}
	if(s.empty()) cout<<"Yes";
	else cout<<"No";
	cout<<endl;
}