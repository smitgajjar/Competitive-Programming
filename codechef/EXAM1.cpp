#include<bits/stdc++.h>
#define debug(s) cout<<s<<endl<<endl;
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m=0;
		cin>>n;
		string c, s;
		cin>>c>>s;

		for(int i=0; i<n; i++)
		{
			if(s[i]!='N')
			{
				if(i==n-1 and s[i]==c[i])
				{
					m++;
				}
				else if(s[i]!=c[i])
				{
					i++;
				}
				else
					m++;
			}
		}
		cout<<m<<endl;
	}
}