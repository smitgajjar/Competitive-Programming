#include <bits/stdc++.h>
//#define ll long long
//#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
    int n, r, N;
    cin>>n>>r;
    while(n--)
    {
        cin>>N;
        if(N>=r)
            cout<<"Good boi\n";
        else
            cout<<"Bad boi\n";
    }
}
