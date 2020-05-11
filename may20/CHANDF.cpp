#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int t, x, y, l, r, z, maxi;

int posOfMSB(int n)
{
	return(63-__builtin_clz(n));
}

string bin(int r, bool choice=1)
{
	string ans;
	if(choice==0) return to_string(r);
	if(r==0)
		return "0";
	while(r>0)
	{
		ans=to_string(r&1)+ans;
		r>>=1;
	}
	return ans;
}
int32_t main()
{
	// freopen("in.txt", "r", stdin);
	// cin>>t;
	t=1;
	while(t--)
	{
		// cin>>x>>y>>l>>r;
		x=0b1100, y=0b0111, l=0;
		for(int r=0; r<=(x|y); r++)
		{
			z=l;
			maxi=(x&l)*(y&l);
			for(int i=l+1; i<=r; i++)
			{
				if((x&i)*(y&i)>maxi)
				{
					z=i;
					maxi=(x&i)*(y&i);
				}
				// cout<<i<<' '<<bin((x&i)*(y&i))<<endl;
			}
			cout<<"B: "<<bin(r)<<' '<<bin((x|y))<<' '<<bin(z)<<endl;
			cout<<((x&r)*(y&r))<<endl;
			cout<<"D: "<<bin(r, 0)<<' '<<bin((x|y), 0)<<' '<<bin(z, 0)<<endl;
			cout<<endl<<endl;
		}
		int maxz=(x|y);
		if(x==0 or y==0)
			cout<<l<<endl;
		else if(l==0)
		{
			if(r>=maxz)
				cout<<maxz<<endl;
			else if(x&r or y&r)
				cout<<0<<endl;
			else
			{
				cout<<r<<endl;//wrong!!
			}
		}
		else
			cout<<l<<endl;//wrong!
	}
}