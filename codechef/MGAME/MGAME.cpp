#include <bits/stdc++.h>
using namespace std;

int main()
{
	long t;
	cin>>t;
	long n=0, p=1;
	while(t--)
	{

		cin>>n>>p;
		for(long l=1; l<=n; l++)
		{
			for(long m=1; m<=p; m++)
			{
				long max=0;
				long score, c=0;
				unordered_map<long, long> umap;
				for(int i=m; i>=1; i--)
				{
					for(int j=m; j>=1; j--)
					{
						for(int k=m; k>=1; k--)
						{
							score=(((l%i)%j)%k)%l;
							c++;
							if(score>=max)
							{
								max=score;
								umap[max]++;

								//cout<<max<<"    "<<i<<' '<<j<<' '<<k<<'\n';
							}

						}
					}
				}
				cout<<umap[max]<<' ';
				if(m==p)
					cout<<endl;
			}
		}
		
	}
}
