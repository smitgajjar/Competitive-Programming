/* Author: Smit Gajjar
   © 2018
*/
#include <bits/stdc++.h>
//#define ll long long
//#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int h[n+1];
        h[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &h[i]);
        }
        int sum=0, diff;
        for(int i=1; i<=n; i++)
        {
            diff=h[i]-h[i-1];
            if(diff>k && diff%k!=0)
                sum+=(diff/k);
            else if(diff>k && diff%k==0)
                sum+=(diff/k)-1;
        }

        printf("%d\n", sum);
    }
}
