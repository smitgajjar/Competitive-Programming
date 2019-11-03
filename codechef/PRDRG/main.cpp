#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        int y=(1<<n), x=(n%2==1)?((y+1)/3):((y-1)/3);
        cout<<x<<" "<<y<<" ";
    }
}
