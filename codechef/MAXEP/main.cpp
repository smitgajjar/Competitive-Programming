#include <bits/stdc++.h>
#define ll long long
//#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
    ll n;
    int c;
	cin>>n>>c;
	ll value, low=1, temp=0;
    ll diff=(n/10 == 0)?(1):(n/10);
	while(1)
    {
        cout<<"1 "<<low<<endl;
        cin>>value;
        if(value==0)
        {
                temp=low;
                if(low==1 && diff!=1)
                    low=diff;
                else
                    low=low+diff;

        }
        else if(value==1)
        {
            cout<<"2"<<endl;
            if(diff==1)
                break;
            if(diff/10==0)
                diff=1;
            else diff/=10;
            low=temp+diff;

        }
        if(low>n)
        {
            if(diff/10==0)
                diff=1;
            else
                diff/=10;
            low=temp+diff;

        }
    }
    cout<<"3 "<<low<<endl;
}
