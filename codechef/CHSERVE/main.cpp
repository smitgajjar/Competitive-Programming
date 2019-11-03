#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int p1, p2, k, sum;
        scanf("%d %d %d", &p1, &p2, &k);
        sum=p1+p2;
        if((sum/k)%2==0)
            printf("CHEF\n");
        else
            printf("COOK\n");
    }
}
