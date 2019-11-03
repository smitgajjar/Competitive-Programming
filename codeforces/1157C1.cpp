//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200001];
int main()
{
	int t=1;
	//cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		memset(a, 0, sizeof(a));
		for(ll i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		ll i=1, j=n;
		ll maxx=INT_MIN;
		string s;
		ll pre_i;
		while(i<=j)
		{
			if(i==j)
			{
				if(a[i]>maxx)
				{
					if(pre_i!=i)
						s+='R';
					else
						s+='L';
				}
				break;
			}
			pre_i=i;
			if(a[i]==a[j] && a[i]>maxx)
			{
				string s1, s2;
				while(i<j)
				{
					if(a[i]<a[i+1])
					{
						s1+='L';
						i++;
					}
					else
						break;
				}
				while(i<j)
				{
						if(a[j]<a[j-1])
					{
						s2+='R';
						j--;
					}
					else
						break;
				}
				if(s1.length()>s2.length())
					s=s+s1+'L';
				else if(s1.length()<s2.length())
					s=s+s2+'R';
				else if(s1.length()==s2.length())
					s=s+s1+'L';
				break;
			}
			else if(a[i]>maxx and a[j]>maxx)
			{
				if(a[i]<a[j])
				{
					s+='L';
					maxx=a[i];
					i++;
				}
				if(a[i]>a[j])
				{
					s+='R';
					maxx=a[j];
					j--;
				}
			}
			else if(a[i]>maxx)
			{
				s+='L';
				maxx=a[i];
				i++;
			}
			else if(a[j]>maxx)
			{
				s+='R';
				maxx=a[j];
				j--;
			}
			else
				break;
			
		}
		cout<<s.length()<<endl<<s<<endl;

	}
}
