#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int t; 
	cin>>t;
	while(t--)
	{
		ll n, f, d, after_val=LLONG_MAX, after_index=0, ghav=0, q=0, r=1, pi;
		bool flag=0;
		cin>>n;
		vector<ll>a(n-1, 0);
		vector<ll>possible;
		vector<pair<ll, ll>>v;
		for(ll i=0; i<n-1; i++)
		{
			cin>>a[i];
		}
		cin>>f;
		
		if(a[0]<=f)
		{
			possible.push_back(0);
			flag=1;
		}
		for(ll i=0; i<n-1; i++)
		{
			if(a[i]<=f)
			{
				possible.push_back(i);
				flag=1;
			}
		}

		vector<ll>temp(n-1, 0);

		auto i=temp.begin(), j=temp.begin()+1, p=temp.begin() ;

		for(auto k: possible)
		{
			// cout<<k<<endl;
			temp=a;
			temp.insert(temp.begin()+k, 0);
			ghav=0;
			i=temp.begin(), j=temp.begin()+1;
			q=0, r=1;
			p=temp.begin()+k;
			pi=k;
			while(temp.size()>2)
			{

				if(i==p)
				{
					if(next(j,1)!=temp.end())
					{
						j++;
						r++;

					}
					else
					{
						j=temp.begin();
						r=0;
					}
					if(next(i,1)!=temp.end())
					{
						i++;
						q++;
					}
					else
					{
						i=temp.begin();
						q=0;
					}
				}
				else if(j==p)
				{
					// cout<<*i<<endl;
					ghav+=*i;
					if(next(j,1)!=temp.end())
					{
						j++;
						r++;
					}
					else
					{
						j=temp.begin();
						r=0;
					}
					if(next(j,1)!=temp.end())
					{
						j++;
						r++;
					}
					else
					{
						j=a.begin();
						r=0;
					}

					if(next(i,1)!=temp.end())
					{
						i++;
						q++;

					}
					else
					{
						i=temp.begin();
						q=0;
					}
					if(next(i,1)!=temp.end())
					{
						i++;
						q++;
					}
					else
					{
						i=temp.begin();
						q=0;
					}

				}
				else
				{
					cout<<*p<<' '<<*j<<"@"<<' '<<endl;
					cout<<pi<<' '<<r<<"##"<<' '<<endl;
					
					cout<<'h';
					if(temp.size()==3)
					{
						temp.erase(j);
						break;
					}
					else
						j=temp.erase(j);
					
					if(r+1<pi)
					{
						cout<<"hiI";
						p=prev(p, 1);
						pi--;
					}
					cout<<"hi";
					if(temp.size()==2)
						break;
					r++;
					if(j==temp.end())
					{
						j=temp.begin();
						r=0;
					}
					j++;
					r++;
					if(j==temp.end())
					{
						j=temp.begin();
						r=0;
					}
					

					if(next(i,1)!=temp.end())
					{
						i++;
						q++;
					}
					else
					{
						i=temp.begin();
						q=0;
					}
					if(i==p and next(i,1)!=a.end())
					{
						i++;
					}
					else
						i=a.begin();
				}
				for(auto i: temp)
					cout<<i<<endl;
				cout<<"#"<<endl;
			}
			v.push_back({k+1, ghav+f});				
		}
		ll min_ghav=INT_MAX, min_pos=0;
		for(auto o: v)
		{
			if(o.second<min_ghav)
			{
				min_ghav=o.second;
				min_pos=o.first;
			}
		}
		if(flag)
		{
			cout<<"possible"<<endl;
			cout<<min_pos<<' '<<min_ghav<<endl;
		}
		else
			cout<<"impossible"<<endl;
	}
}