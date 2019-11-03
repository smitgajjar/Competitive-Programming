#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	while(1)
	{			
		int n, val, curr=1;
		cin>>n;
		if(n==0)
			break;
		stack<int>s;
		for(int i=0; i<n; i++)
		{
			cin>>val;
			if(val==curr)
				curr++;
			else
			{
				s.push(val);
			}
			while(!s.empty() and s.top()==curr)
			{
				s.pop();
				curr++;
			}
		}
		
		if(s.empty())
			cout<<"yes";
		else
			cout<<"no";
		cout<<endl;
	}

}