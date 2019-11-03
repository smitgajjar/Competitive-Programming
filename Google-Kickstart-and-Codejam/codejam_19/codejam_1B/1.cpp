//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t=1;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		int p;
		ll q, tx, ty, y_min=INT_MAX, y_max=INT_MIN, x_min=INT_MAX, x_max=INT_MIN;
		bool flagN=0, flagS=0, flagE=0, flagW=0;
		char c;
		cin>>p>>q;
		vector<ll>ix, iy;
		for(int i=0; i<p; i++)
		{
			cin>>tx>>ty>>c;
			
			
			if(c=='N') y_min=min(y_min, ty+1), flagN=1, iy.push_back(ty);;
			if(c=='S') y_max=max(y_max, ty-1), flagS=1, iy.push_back(ty);;

			if(c=='E') x_min=min(x_min, tx+1), flagE=1, ix.push_back(tx);;
			if(c=='W') x_max=max(x_max, tx-1), flagW=1, ix.push_back(tx);;
		}
		if(!flagN) y_min=0;
		if(!flagS) y_max=q;
		if(!flagE) x_min=0;
		if(!flagW) x_max=q;
		ll ansx=0, ansy=0, minn=INT_MAX;
		
		for(ll i=y_min; i<=y_max; i++)
		{
			ll sum=0;
			for(auto j: iy)
			{
				sum+=abs(j-i);
			}
			if(sum<minn)
			{
				ansy=i;
				minn=sum;
			}
		}
		minn=INT_MAX;
		for(ll i=x_min; i<=x_max; i++)
		{
			ll sum=0;
			for(auto j: ix)
			{
				sum+=abs(j-i);
			}
			if(sum<minn)
			{
				ansx=i;
				minn=sum;
			}
		}
		cout<<"Case #"<<tt<<": "<<ansx<<' '<<ansy<<endl;
	}
}