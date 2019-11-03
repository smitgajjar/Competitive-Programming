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
        int m, x, y;
        cin>>m>>x>>y;
        int range=x*y, a[m], num=0;
        bool flag;
        for(int i=0; i<m; i++)
        {
            cin>>a[i];
        }
        for(int h_no=1; h_no<=100; h_no++)
        {
            flag=1;
            for(int i=0; i<m; i++)
            {
                if(h_no<=min(a[i]+range, 100) && h_no>=max(a[i]-range, 1))
                    flag=0;
            }
            if(flag)
                num++;
        }
        cout<<num<<endl;
    }
}
