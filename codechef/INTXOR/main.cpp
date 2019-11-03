#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;



ll ask(int x, int y, int z)
{
    ll value;
    cout<<"1 "<<x<<" "<<y<<" "<<z<<endl;
    fflush(stdout);
    cin>>value;
    return value;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> a(n+1 , -1);
        a[0]=0;
        ll no=n%4;
        if(no==0)
        {
            ll x1, x2, x3, x4;
            for(int i=0; i<n; i+=4)
            {
                x1=ask(i+1, i+2, i+3);
                x2=ask(i+2, i+3, i+4);
                x3=ask(i+1, i+2, i+4);
                x4=ask(i+1, i+3, i+4);
                ll x12, x34, x1234;
                x12=(x2^x4);
                x34=(x1^x3);
                x1234=x12^x34;
                a[i+1]=x1234^x2;
                a[i+2]=x1234^x4;
                a[i+3]=x1234^x3;
                a[i+4]=x1234^x1;
            }
        }
        else if(no==1)
        {
            ll x1, x2, x3, x4, x5;
            x1=ask(1, 2, 3);
            x2=ask(2, 3, 4);
            x3=ask(3, 4, 5);
            x4=ask(1, 4, 5);
            x5=ask(1, 2, 5);

            a[5]=(x1^x2^x4);
            a[3]=(a[5]^x5^x1);
            a[4]=(a[3]^a[5]^x3);
            a[2]=(a[3]^a[4]^x2);
            a[1]=(a[2]^a[3]^x1);

            for(int i=5; i<n; i+=4)
            {
                x1=ask(i+1, i+2, i+3);
                x2=ask(i+2, i+3, i+4);
                x3=ask(i+1, i+2, i+4);
                x4=ask(i+1, i+3, i+4);
                ll x12, x34, x1234;
                x12=(x2^x4);
                x34=(x1^x3);
                x1234=x12^x34;
                a[i+1]=x1234^x2;
                a[i+2]=x1234^x4;
                a[i+3]=x1234^x3;
                a[i+4]=x1234^x1;
            }
        }
        else if(no==2)
        {
            ll x1, x2, x3, x4, x5, x6, x1234, x3456, x1256;
            x1=ask(1, 3, 4);
            x2=ask(3, 5, 6);
            x3=ask(1, 2, 5);
            x4=ask(2, 3, 4);
            x5=ask(4, 5, 6);
            x6=ask(1, 2, 6);
            x1234=(x1^x2^x4^x5);
            x3456=(x2^x3^x5^x6);
            x1256=(x1^x3^x4^x6);
            a[1]=x1234^x4;
            a[2]=(x1234^x1);
            a[3]=(x3456^x5);
            a[4]=(x3456^x2);
            a[5]=x1256^x6;
            a[6]=x1256^x3;
            for(int i=6; i<n; i+=4)
            {
                x1=ask(i+1, i+2, i+3);
                x2=ask(i+2, i+3, i+4);
                x3=ask(i+1, i+2, i+4);
                x4=ask(i+1, i+3, i+4);
                ll x12, x34, x1234;
                x12=(x2^x4);
                x34=(x1^x3);
                x1234=x12^x34;
                a[i+1]=x1234^x2;
                a[i+2]=x1234^x4;
                a[i+3]=x1234^x3;
                a[i+4]=x1234^x1;
            }
        }
        else if(no==3)
        {
            ll x1, x2, x3, x4, x5, x6, x7;
            x1 = ask(1 , 2 , 3);
            x2 = ask(1 , 2 , 4);
            x3 = ask(5 , 6 , 2);
            x4 = ask(5 , 6 , 7);
            x5 = ask(3 , 4 , 7);
            x6 = ask(3 , 4 , 5);
            x7 = ask(1 , 6 , 7);
            a[7] = (x1 ^ x2 ^ x5);
            a[5] = (x1 ^ x2 ^ x6);
            a[6] = (x4 ^ a[5] ^ a[7]);
            a[1] = (x7 ^ a[6] ^ a[7]);
            a[2] = (x3 ^ a[5] ^ a[6]);
            a[3] = (x1 ^ a[1] ^ a[2]);
            a[4] = (x6 ^ a[3] ^ a[5]);
            for(int i=7; i<n; i+=4)
            {
                x1=ask(i+1, i+2, i+3);
                x2=ask(i+2, i+3, i+4);
                x3=ask(i+1, i+2, i+4);
                x4=ask(i+1, i+3, i+4);
                ll x12, x34, x1234;
                x12=(x2^x4);
                x34=(x1^x3);
                x1234=x12^x34;
                a[i+1]=x1234^x2;
                a[i+2]=x1234^x4;
                a[i+3]=x1234^x3;
                a[i+4]=x1234^x1;
            }

        }
        cout<<2<<" ";
        for(int i=1; i<=n; i++)
            cout<<a[i]<<" ";
        cout<<endl;
        fflush(stdout);
        int corr;
        cin>>corr;
        if(corr!=1)
            return 0;
    }

    return 0;

}
