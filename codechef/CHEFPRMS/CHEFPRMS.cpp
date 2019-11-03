#include<bits/stdc++.h>
using namespace std;
int semiprime(int);
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, n1, flag=0;
        scanf("%d", &n);
        for(n1=6; n1<=n; n1++)
        {
            if(semiprime(n1) && semiprime(n-n1))
            {
               flag=1;
               //printf("  %d  \n", n1);
               break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
int semiprime(int n1)
{
    int cnt=0, temp=n1, temp2;
    for(int i=2; i<=sqrt(n1) && cnt<2; i++)
    {
        while(n1%i==0)
        {
            n1/=i;
            if((n1*n1)!=temp)
                ++cnt;
        }

    }
    if(n1>1)
        ++cnt;

    return cnt==2;
}
