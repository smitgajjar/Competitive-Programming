
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int a[n+1];

        for(int i=1; i<=n; i++)
            scanf("%d", &a[i]);

        int j=1, sum=0, day=0;
        if(a[1]>=n-1)
            printf("1\n");
        else{
                for(int i=j; i<=a[j]+1 && j<=sizeof(a)/sizeof(a[0]); i++)
                {
                    if(sum<(n-1))
                        sum=sum+a[i];
                    if(i==(a[j]+1))
                    {
                        j=sum;
                        day++;
                    }


                }

            printf("%d\n", day);
        }

    }
}
