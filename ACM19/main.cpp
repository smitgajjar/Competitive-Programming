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
        string s;
        cin>>s;
        int r[s.size()+1];
        int v[s.size()+1];
        int flag=0,j=0;
        for(int i=0; i<s.size(); i++)
        {
            /*
            if(s[i]=='.')
            {
                r[i]=0;
            }
            else
                r[i]=s[i];
                */

            if(s[i]!='.')
            {
                v[j]=(s[i]-48);
                r[j]=i;
                j++;
            }
        }
        for(int i=1; i<j; i++)
        {
            int diff=r[i]-r[i-1];
            if(diff<=v[i]+v[i-1])
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
            printf("unsafe\n");
        else
            printf("safe\n");


    }
}
