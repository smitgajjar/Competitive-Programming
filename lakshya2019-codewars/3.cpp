//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
        ll a, b, v;
        cin>>a>>b>>v;
        bool flag=0;
    if(v<=max(a, b))
    {
        if(v%a==0) flag=1;
        if(v%b==0) flag=1;
        if(a<b)
        {

            if(v%(b-a)==0)
            {
                flag=1;
            }

        }
        else if(a>b)
        {
            if(v%(a-b)==0)
            {
                flag=1;
            }

        }

    }


        cout<<(flag?"YES\n":"NO\n");
	}
}
