/* Author: Smit Gajjar
   © 2018
*/
#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

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
        int a, b, sum;
        scanf("%d", &a);
        b=dsum(a+1);
        while(b%10!=b)
        {
            b=dsum(b);
        }
        printf("%d\n", b);
    }
}
