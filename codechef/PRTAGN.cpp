#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		bool flago=0, flage=0, done=0, not_done=0;
		ll q, x, e=0, o=0, val;
		set<ll>s;
		cin>>q;
		while(q--)
		{
			// x=rand()%100000+1;

			// if(__builtin_popcount(x)%2==0)
			// 	continue;
		// for(auto i: s) cout<<i<<' ';

			// cout<<endl<<x<<' '<<'#'<<' '<<__builtin_popcount(x)%2<<"    "<<endl<<endl;

			cin>>x;
			
			
			
			if(!flage and __builtin_popcount(x)%2==0)
				flage=1;
			if(!flago and __builtin_popcount(x)%2==1)
				flago=1;

			if(s.find(x)==s.end())
			{
				if(done)
				{
					o<<=1LL;
					e=o-1;
				}
				else if(flago)
				{
					o=e+1;
					done=1;
				}
				else if(flage and !flago and !not_done)
				{
					o=0;
					e=1;
					not_done=1;
				}
				else
				{
					e=((e+1)<<1LL)-1;
				}
			
				s.insert(x);
				for(auto i: s)
				{
					if(i!=x)
						s.insert(i^x);
				}
			}
			// x=rand()%1000+1;
			// if (__builtin_popcount(x)%2==0)
			// 	continue;
			// for(auto i: s) cout<<i<<' ';

			// cout<<endl<<x<<' '<<'#'<<' '<<__builtin_popcount(x)%2<<"    ";
			
			// if(!s.empty())
			// {
				// if(s.find(x)==s.end())
				// {
				// 	if(__builtin_popcount(x)%2==0)
				// 		e++;
				// 	else
				// 		o++;
				// }
				// s.insert(x);
				
				// for(auto i: s)
				// {
				// 	if(i!=x)
				// 	{
				// 		val=i^x;
				// 		if(s.find(val)==s.end())
				// 		{	
				// 			if(__builtin_popcount(val)%2==0)
				// 				e++;
				// 			else
				// 				o++;
				// 			s.insert(val);
				// 		}
						
				// 	}
				// }
				
			// }
			// else
			// {
				// s.insert(x);
				// if(__builtin_popcount(x)%2==0)
				// 	e++;
				// else
				// 	o++;
			// }
			cout<<e<<' '<<o<<endl;

		}
	}
}