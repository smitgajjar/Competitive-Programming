#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n, neg=0, pos=0;
        ll a;
        cin>>n;
        for(long i=0; i<n; i++)
        {
            cin>>a;
            if(a<0)
                neg++;
            else if(a>0)
                pos++;
        }
        if(pos && !neg)
            cout<<pos<<' '<<pos<<endl;
        else if(!pos && neg)
            cout<<neg<<' '<<neg<<endl;
        else if (pos && neg)
        {
            if(pos>neg)
                cout<<pos<<' '<<neg<<endl;
            else
                cout<<neg<<' '<<pos<<endl;
        }
    }
}
