#include <bits/stdc++.h>
#define ll long long
//#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int tr, dr, ts, ds;
        cin>>tr;
        int atr[tr];
        for(int i=0; i<tr; i++)
        {
            cin>>atr[i];
        }


        cin>>dr;
        int adr[dr];
        for(int i=0; i<dr; i++)
        {
            cin>>adr[i];
        }

        cin>>ts;
        int temp=0;
        bool twon=true;
        for(int i=0; i<ts; i++)
        {
            int flag=0;
            cin>>temp;
            for(int j=0; j<tr; j++)
            {
                if(temp==atr[j])
                    flag=1;
            }
            if(!flag)
            {
                twon=false;
                break;
            }
        }


        cin>>ds;
        temp=0;
        bool dwon=true;
        for(int i=0; i<ds; i++)
        {
            int flag=0;
            cin>>temp;
            for(int j=0; j<dr; j++)
            {
                if(temp==adr[j])
                    flag=1;
            }
            if(!flag)
            {
                dwon=false;
                break;
            }
        }

        if(twon && dwon)
        {
            cout<<"yes\n";
        }
        else
            cout<<"no\n";
    }
}
