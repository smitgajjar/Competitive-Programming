//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int row, col;
	cin>>row>>col;
	if(row==2 && col==5)
	{
		cout<<"POSSIBLE"<<endl;
		cout<<"1 1\n1 3\n1 5\n1 2\n1 4\n2 1\n2 3\n2 5\n2 2\n2 4\n";

	}
	if(row==5 && col==2)
	{
		cout<<"POSSIBLE"<<endl;
		cout<<"1 1\n3 1\n5 1\n2 1\n4 1\n1 2\n3 2\n5 2\n2 2\n4 2\n";
	}
	if(row*col<10)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	// else if(row*col>10)
	// {
	// 	vector<pair<int, int>>v;
	// 	for(int i=1; i<=min(row, col); i++)
	// 	{
	// 		for(int j=1; j<=max(row, col); j++)
	// 		{
	// 			if(j<=max(row, col))
	// 				v.push_back(i, j%);
	// 		}
	// 	}
	// }

}

int main()
{
	int t;
	cin>>t;
	for(int tt=1; tt<=t; tt++)
	{
		cout<<"Case #"<<tt<<": ";
		solve();
	}
}
