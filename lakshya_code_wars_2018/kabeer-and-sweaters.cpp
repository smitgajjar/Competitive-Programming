#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
int main()
{
	int n;
	long s;
	cin>>n>>s;
	int value;
	vector<pair<int, int>> a;
	for(int i=0; i<n; i++)
	{
		cin>>value;
		a.push_back({value, i});
	}
	sort(a.begin(), a.end(), sortbysec);
	int k=1, prev_k=0;
	long t=0, prev_t=0;
	// for(int i = 0; i<n ;i++)
	// 	cout<<a[i].first<<' '<<a[i].second<<endl;
	while(k<=n)
	{
		t=0;
		for(int i=0; i<k; i++)
		{
			t=t+(a[i].first+(a[i].second+1)*k);
		}
		if(t<=s)
		{
			if(t<prev_t || k!=0)
			{
				prev_t=t;
				prev_k=k;
			}
				
		}
		k++;
	}
	cout<<prev_k<<' '<<prev_t<<endl;
}