#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> a(n+1);
	    vector<int> counter(n+1, 0);
	    vector<bool> visited(n+1, false);
	    bool flag=false;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=1; i<=n; i++)
        {
            if(!visited[a[i]])
            {
                visited[a[i]]=true;
                counter[a[a[i]]]++;
                if(counter[a[a[i]]]==2)
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Truly Happy\n";
        else
            cout<<"Poor Chef\n";


	}
}
