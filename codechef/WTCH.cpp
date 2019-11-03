#include<bits/stdc++.h>
using namespace std;
long long main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n, count=0;
		cin>>n;
		string s;
		s.clear();
		cin>>s;
		//cin.ignore('\n');
		if(s.find('1')==string::npos)
		{
			count=((n+1)/2);
		}
		else
		{
			long long l=0, r=0, flag=0, tc=0, len;
			for(long long i=0; i<n; i++)
			{
				if((i==0 && s[0]=='0'))
				{
					len=s.find('1');
					if(len>1)
					{
						count+=((len)/2);
					}
				}
				if(i==(n-1) && (s[n-1]=='0'))
				{
						len=n-s.rfind('1')-1;
						count+=((len)/2);
						//cout<<len<<"!!"<<endl;
						break;
				}
				if(s[i]=='1')
				{	
					if(tc==0)
					{
						l=i;
						tc=1;
					}
					else
					{
						r=i;
						len=r-l-1;
				
						//cout<<l<<' '<<r<<' '<<len<<" hi"<<i<<' '<<endl;
						if(len>=3)
						{
							if(len%2)
								count+=((len)/2);
							else
								count+=((len-1)/2);
							
						}
						l=r;

					}

				}
				


			}
		}

		cout<<count<<endl;
	}
}