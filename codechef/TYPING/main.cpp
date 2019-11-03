#include <stdio.h>
#include<bits/stdc++.h>

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
int main()
{
    unsigned char strings[3][256];
    scanf("%s %s %s", strings[0], strings[1], strings[2]);

    unsigned long value0=hash(strings[0]);
    unsigned long value1=hash(strings[1]);
    unsigned long value2=hash(strings[2]);

    printf("%ld %ld %ld", value0, value1, value2);
}
