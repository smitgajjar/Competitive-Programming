#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>>visi;
vector<int>v;
void solve(int i, vector<short>a)
{
    if(v.find())
    v.push_back(i);
    visi.push_back(v);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<short> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        solve(0, a);
    }
}
