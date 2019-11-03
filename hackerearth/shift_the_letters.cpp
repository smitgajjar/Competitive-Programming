#include <bits/stdc++.h>
using namespace std;

bool isNonZero(int i)
{
		return (i!=0);
}
bool notZero_min(int a, int b)
{
	return ((a<b) && (a!=0) && (b!=0)); 
}
int main()
{
	string s;
	int k;
	cin>>s;
	cin>>k;
	int diff[s.size()-1];
	

	//map<int, int> diff;
	int mind=INT_MAX, pos;
	for(int i=0; i<s.size()-1; i++)
	{
		diff[i]=min(abs(s[i+1]-s[i]), 26-abs(s[i+1]-s[i]));
		if(diff[i]<=mind && diff[i]!=0)
			mind=diff[i], pos=i;
	}

	if(count_if(diff, diff+sizeof(diff)/sizeof(diff[0]), isNonZero)==k)
	{
		cout<<"0\n";

	}
	else
	{
		int count=0;
		int pos=0;
		while(count_if(diff, diff+sizeof(diff)/sizeof(diff[0]), isNonZero)!=(k))
		{

			
			//pos=distance(diff, (min_element(diff, diff +sizeof(diff)/sizeof(diff[0]), notZero_min) ));
			
			if(((s[pos]<s[pos+1]) && abs(s[pos+1]-s[pos])<=13) || ((s[pos]>s[pos+1]) && abs(s[pos+1]-s[pos])>13))
			{
				s[pos]+=diff[pos];
				if(s[pos]>122)
					s[pos]=(s[pos]-123+97);
				//cout<<"if1\n";

				count+=diff[pos];
				//diff[pos]=0;
				// if(pos!=0)
				// 	diff[pos-1]=min(abs(diff[pos-1]-diff[pos]), 26-abs(diff[pos-1]-diff[pos]));


			}
			else if(((s[pos]<s[pos+1]) && abs(s[pos+1]-s[pos])>13) || ((s[pos]>s[pos+1]) && abs(s[pos+1]-s[pos])<=13))
			{
				//cout<<"if2\n";
				s[pos+1]+=diff[pos];
				if(s[pos+1]>122)
					s[pos+1]=(s[pos+1]-123+97);
				//diff[pos+1]=0;
				count+=diff[pos];
				// if((pos+1)!=(s.size()-1))
				// 	diff[pos+2]=min(abs(diff[pos+2]-diff[pos+1]), 26-abs(diff[pos+2]-diff[pos+1]));


			}
			mind=INT_MAX;
			for(int i=0; i<s.size()-1; i++)
			{
				diff[i]=min(abs(s[i+1]-s[i]), 26-abs(s[i+1]-s[i]));
				if(diff[i]<=mind && diff[i]!=0)
					mind=diff[i], pos=i;
			} 
			//cout<<count<<endl;


		}
		// for(int i: diff)
		// 	cout<<i<<' ';
		// cout<<count_if(diff, diff+sizeof(diff)/sizeof(diff[0]), isNonZero)<<endl;
		cout<<count;
	}
	

}	