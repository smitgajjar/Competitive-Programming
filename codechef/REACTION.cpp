//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	// sort(v.begin(), v.end(), compare);
	int t=1;
	cin>>t;
	while(t--)
	{
		int r,c ;
		cin>>r>>c;
		int a[r][c];
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				cin>>a[i][j];
			}
		}
		bool flag=1;
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				int curr=a[i][j];
				if(curr==4)
				{
					flag=0; 
					break;
				}
				else if(i==0 && j==0 && curr>1)
				{
					flag=0;
					break;
				}
				else if(i==0 && j==c-1 && curr>1)
				{
					flag=0;
					break;
				}
				else if(i==r-1 && j==0 && curr>1)
				{
					flag=0;
					break;
				}
				else if(i==r-1 && j==c-1 && curr>1)
				{
					flag=0;
					break;
				}
				else if(i==0 && (j!=0 && j!=c-1) && curr>2)
				{
					flag=0;
					break;
				}
				else if(i==r-1 && (j!=0 && j!=c-1) && curr>2)
				{
					flag=0;
					break;
				}

				else if(j==0 && (i!=0 && i!=r-1) && curr>2)
				{
					flag=0;
					break;
				}
				else if(j==c-1 && (i!=0|| i!=r-1) && curr>2)
				{
					flag=0;
					break;
				}
				else if(curr>3)
				{
					flag=0;
					break;
				}

			}
			if(flag==0)
				break;
		}
		cout<<(flag?"Stable":"Unstable")<<endl;

	}
}