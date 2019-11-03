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
        int a[n], b[n];
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &b[i]);
            b[i]-=a[i];
        }
        int diff, prev_diff, new_diff, flag=1, temp;
        for(int i=0; i<n-1; i++)
        {

            if(diff>prev_diff && i!=0)
            {
                temp=diff;
                diff=diff-prev_diff;
                continue;
            }
            else
                diff=b[i+1]-b[i];
            if(diff!=temp)
            {
                flag=0;
                break;
            }

            prev_diff=diff;


        }
        if(flag)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
}
