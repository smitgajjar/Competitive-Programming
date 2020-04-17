#include<bits/stdc++.h>
using namespace std;

int n, tim, maxx, cnt0, sum;
char movie;
int arr[4][4];
int permut[4]={0, 1, 2, 3};
int curr[4];
int main()
{
	sum=0;
	// freopen("in_.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				arr[i][j]=0;
		for(int i=0; i<n; i++)
		{
			cin>>movie>>tim;
			arr[movie-'A'][(tim/3)-1]++;
		}
		cnt0=0;
		for(int i=0; i<4; i++)
		{
			curr[i]=arr[i][i];
			if(curr[i]==0)
				cnt0++;
		}
		sort(curr, curr+4);
		maxx=(curr[0]*25+curr[1]*50+curr[2]*75+curr[3]*100)-(cnt0*100);
		while(next_permutation(permut, permut+4))
		{
			cnt0=0;
			for(int i=0; i<4; i++)
			{
				curr[i]=arr[permut[i]][i];
				if(curr[i]==0)
					cnt0++;
				// cout<<curr[i]<<"!!";
			}
			// cout<<endl;
			sort(curr, curr+4);
			maxx=max(maxx, (curr[0]*25+curr[1]*50+curr[2]*75+curr[3]*100)-(cnt0*100));
			// cout<<maxx<<endl;
			// cnt++;
		}
		cout<<maxx<<endl;
		sum+=maxx;
	}
	cout<<sum<<endl;
}