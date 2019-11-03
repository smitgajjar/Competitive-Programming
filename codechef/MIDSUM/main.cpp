#include<bits/stdc++.h>
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);
#define ll long long
#define size 100
using namespace std;
int dsum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d",&n, &k);
        int cnt=0;
       /* while(k%10!=k)
        {
            k=dsum(k);
        }
        while(n%10!=n)
        {
            n=dsum(n);
            cnt++;
        }*/

        int a[size], c[size], add=n;
        for(int i=0; i<size; i++)
        {
            if(i!=0)
                n=n+k;
            a[i]=n;
            c[i]=0;
            while(a[i]%10!=a[i])
            {
                a[i]=dsum(a[i]);
                c[i]++;
            }
        }


        int mini=a[0], j=0, freq;
        for(int i=0; i<size;i++)
        {
            //printf("%d ", a[i]);
            if(a[i]<mini)
            {
                mini=a[i];
                j=i;
            }
        }
        //printf("\n");
        freq=c[j]+j;

        printf("%d %d\n", mini, freq);
    }
}
