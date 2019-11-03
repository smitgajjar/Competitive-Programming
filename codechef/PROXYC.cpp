#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			int d, p=0, proxy=0;
		string s;
		cin>>d>>s;
		for(int i=0; i<d; i++)
		{
			if(s[i]=='P')
				p++;
			else if(i>=2 and i<d-2)
			{
				if((s[i-1]=='P' or s[i-2]=='P') and (s[i+1]=='P' or s[i+2]=='P'))
				{
					proxy++;
				}
			}	
		}
		float ans=0.75*d-p;
		int req=(ans>0)?ceil(ans):0;
		//cout<<ans<<' '<<p<<' '<<proxy<<' '<<d<<	endl;
		if(req<=proxy)
			cout<<req<<endl;
		else
			cout<<-1<<endl;

	}
}