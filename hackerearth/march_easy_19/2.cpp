//Smit Gajjar
#include <bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0) 
using namespace std;
int main()
{
	io;
	string a, b, f;
	cin>>a>>b;
	f=a+b;
	int n=f.length();
	bool tab[n][n];
	memset(tab, 0, sizeof(tab));

	int max=1;
	for (int i=0; i<n; i++)
		tab[i][i]=1;

	int start=0;
	for(int i=0; i<n-1; i++)
	{
		if(f[i]==f[i+1])
		{
			tab[i][i+1]=1;
			start=i;
			max=2;
		}
	}
	for(int p=3; p<=n; ++p)
	{
		for(int i=0; i<n-p+1; ++i)
		{
			int j=i+p-1;
			if(tab[i+1][j-1] && f[i]==f[j])
			{
				tab[i][j]=1;
				if(p>max)
				{
					start=i, max=p;
				}
			}
		}
	}
	cout<<max<<endl;

}