#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
    {
        int n,k;
        scanf("%d %d", &n, &k);

        int a[n], sum=0, flag=0;

        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        if(n>1)
        {
            for(int i=1; i<n; i++)
            {
                while(a[i-1]>k && a[i]>k)
                {
                    a[i-1]--;
                    a[i]--;
                    flag=1;
                }
                if(a[i-1]>a[i])
                {
                    swap(a[i-1], a[i]);

                }
            }
            for(int i=0; i<n; i++)
            {
                sum+=a[i];
            }
            printf("%d\n", sum);
        }
        else
            printf("%d\n", a[0]);


    }
}
