//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve()
{
	int n, cnt=0;
	cin>>n;
	vector<string>temp(n);
	for(int i=0; i<n; i++)
		cin>>temp[i], reverse(temp[i].begin(), temp[i].end());
	set<string>s;
	vector<string>ans(n);
	string stri;
	for(int i=0; i<temp.size(); i++)
	{
		ans.clear();
		for(int j=i; j<temp.size(); j++)
		{
			ll k=0;
			stri.clear();
			while(k<=min(temp[i].length(), temp[j].length()))
			{
				if(temp[i][k]==temp[j][k])
					stri+=temp[i][k];
				else
				{
					if(stri.length()!=0 && s.find(stri)==s.end())
						ans.push_back(stri);
					break;
				}
				k++;
			}


		}
		int maxlen=INT_MIN;
		for(int p=0; p<ans.size(); p++)
		{
			if(ans[i].length()>maxlen)
				maxlen=ans[i].length(), stri=ans[i];
		}

		if(ans.size()!=0)
			temp.erase(std::remove(temp.begin(), temp.end(), stri), temp.end()), s.insert(stri), cnt++;
	}
	return cnt;
}

int main()
{
	int t, cnt;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		cnt=solve();
		cout<<"Case #"<<tt<<": "<<cnt*2<<endl;
	}
}
