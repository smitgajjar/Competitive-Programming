#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	while(1)
	{
		ll n;
		cin>>n;
		if(n==0)
			break;
		ll h[n];
		for(ll i=0; i<n; i++)
			cin>>h[i];

		ll i=0, currTop, area_incl_currTop, max_area=INT_MIN;
		stack<ll>s;
		while(i<n)
		{
			if(s.empty() || h[s.top()]<=h[i])
			{
				s.push(i);
				i++;
			}
			else
			{
				currTop=s.top();
				s.pop();

				if(s.empty())
					area_incl_currTop=h[currTop]*i;
				else
					area_incl_currTop=h[currTop]*(i-s.top()-1);
				if(area_incl_currTop>max_area)
					max_area=area_incl_currTop;
			}
		}
		while(!s.empty())
		{
			currTop=s.top();
			s.pop();

			if(s.empty())
				area_incl_currTop=h[currTop]*i;
			else
				area_incl_currTop=h[currTop]*(i-s.top()-1);
			if(area_incl_currTop>max_area)
				max_area=area_incl_currTop;
		}
		cout<<max_area<<endl;

	}
}