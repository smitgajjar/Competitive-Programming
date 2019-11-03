#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, minv=INT_MAX;
    cin>>m;
    int a[m];
    set<int>s;
    for(int i=0; i<m; i++)
    {
       cin>>a[i];
       minv=min(a[i], minv);
    }
    int mod, j, i, prev;
    for(j=2; j<=minv; j++)
    {
        for(i=0; i<m; i++)
        {
            mod=a[i]%j;
            if(i!=0 && mod!=prev)
            {
                break;
            }
            prev=mod;
        }
        //cout<<i<<endl;
        if(i==m)
        {
            s.insert(j);
        }
    }
    for(auto i: s)
        cout<<i<<' ';
}
