#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n, bit=0, nibble=0, byte=0;
        scanf("%d", &n);
        int coefficient=(n-1)/26;
        if((((n-1)%26)/2)==0)
            bit++;
        else if((((n-1)%26)/10)==0)
            nibble++;
        else if((((n-1)%26)/26)==0)
            byte++;
        printf("%d %d %d\n", (bit)<<coefficient, nibble<<coefficient, byte<<coefficient);
    }
}
