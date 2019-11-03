//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	// sort(v.begin(), v.end(), compare);
	int t=1;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		int a;
		cin>>a;
		vector<string>v(a);
		//vector<set<char>>st(1000);
		for(int i=0; i<a; i++)
		{
			cin>>v[i];
		}
		char ch[255][500]={'\0'};

		vector<bool>flagg(a, true);
		for(int i=0; i<a; i++)
		{
			for(int j=0; j<v[i].size(); j++)
			{
				ch[i][j]=v[i][j];
			}
			// cout<<ch[i][v[i].size()]<<endl;
		}
		bool br=0;
		for(int i=0; i<a; i++)
		{
			int k=0;
			br=0;
			while(1)
			{
				for(int j=0; j<v[i].size(); j++)
				{
					if(j+k>=500)
					{
						br=1;
						break;
					}
					ch[i][j+k]=v[i][j];
				}
				k++;
				if(br) break;
			}
			// cout<<ch[i][v[i].size()]<<endl;
		}
		bool flagR, flagP, flagS, flag=1;
		string ans;
		vector<int>Ri, Pi, Si;
		Ri.clear();
		Pi.clear();
		Si.clear();
		for(int j=0; j<500; j++)
		{	
			flagR=0, flagP=0, flagS=0;
			for(int i=0; j<a; i++)
			{
				if(flagg[i])
				{	
					if(ch[i][j]=='R')
					{
						flagR=1;
						Ri.push_back(i);
					}
					if(ch[i][j]=='P')
					{
						flagP=1;
						Pi.push_back(i);
					}	
					if(ch[i][j]=='S')
					{
						flagS=1;
						Si.push_back(i);
					}	
				}
			}
			if(flagR and flagP and flagS)
			{
				flag=0;
				break;
			}
			else if(!flagR and flagP and flagS)
			{
				ans+='S';
				for(auto i: Pi)
					flagg[i]=0;
			}
			else if(flagR and !flagP and flagS)
			{
				ans+='R';
				for(auto i: Si)
					flagg[i]=0;
			}
			else if(flagR and flagP and !flagS)
			{
				ans+='P';
				for(auto i: Ri)
					flagg[i]=0;
			}
			else if(flagR and !flagP and !flagS)
			{
				ans+='P';
				flag=1;
				break;
			}
			else if(!flagR and flagP and !flagS)
			{
				ans+='S';
				flag=1;
				break;
			}
			else if(!flagR and !flagP and flagS)
			{
				ans+='R';
				flag=1;
				break;
			}
			// cout<<ch[i][v[i].size()]<<endl;
		}

		
		//bool flag=0;
		// for(auto i: v)
		// {
		// 	int k=0;
		// 	while(k<1000)
		// 	{
		// 		for(char j: i)
		// 		{
		// 			st[k].insert(j);
		// 			k++;
		// 			if(k>=1000)
		// 				break;
		// 		}
		// 	}
		// }
		// string ans;
		
		// for(auto i: st)
		// {
		// 	if(i.size()==3)
		// 	{
		// 		flag=0;
		// 		break;
		// 	}
		// 	else if(i.size()==2)
		// 	{
		// 		auto itr=i.begin();
		// 		if(*itr=='R')
		// 			ans+='R';
		// 		else if(*itr=='P')
		// 			ans+='P';
		// 		else if(*itr=='S')
		// 			ans+='S';
		// 		flag=0;
		// 	}
		// 	else if(i.size()==1)
		// 	{
		// 		auto itr=i.begin();
		// 		if(*itr=='R')
		// 			ans+='P';
		// 		else if(*itr=='P')
		// 			ans+='S';
		// 		else if(*itr=='S')
		// 			ans+='R';
		// 		flag=1;
		// 		break;
		// 	}	
		// }
		cout<<"Case #"<<tt<<": ";
		if(flag)
		{
			cout<<ans;
		}
		else
		{
			cout<<"IMPOSSIBLE";
		}
		cout<<endl;
	}
}