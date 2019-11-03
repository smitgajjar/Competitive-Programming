/* Author: Smit Gajjar
   © 2018
*/
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
        int n;
        string s;
        cin>>n>>s;
        char s1[100], s2[100], temp[100];
        int cntDE=0, cntDU=0;
        for(int i=0; i<n;i++)
        {
            scanf("%s", &temp);
            if(temp[0]=='0')
                cntDE++;
            else if(temp[0]=='1')
                cntDU++;
        }
        if(s=="Dee")
        {
            if(cntDE<=cntDU)
                printf("Dee\n");
            else
                printf("Dum\n");
        }
        else
        {
            if(cntDU<=cntDE)
                printf("Dum\n");
            else
                printf("Dee\n");
        }
    }
}
