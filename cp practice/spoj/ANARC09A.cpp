#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t=0;
	while(1)
	{
		t++;
		string a;
		cin>>a;
		if(a[0]=='-')
			break;
		stack<int>s;
		for(char c: a)
		{
			if(c=='{')
				s.push(c);
			else
			{
				if(!s.empty() and s.top()=='{')
					s.pop();
				else
					s.push(c);
			}
		}
		char top1, top2;
		int ans=0;
		while(!s.empty())
		{
			 top1=s.top();s.pop();
			 top2=s.top();s.pop();
			 if((top1=='{' and top2=='{') or (top1=='}' and top2=='}'))
			 	ans+=1;
			 else if(top1=='{' and top2=='}')
			 {
			 	ans+=2;
			 }
			 // cout<<top1<<' '<<top2<<endl;
		}
		cout<<t<<". "<<ans<<endl;
	}
}