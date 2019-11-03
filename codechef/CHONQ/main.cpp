#include <bits/stdc++.h>
#define ll long long
using namespace std;

class myclass
{
public:
  ll idx, val;
};
bool byprio(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.second/(double)a.first)>(b.second/(double)b.first);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,some, k, p, sum=0, ans;
        cin>>n>>k;
        //vector<ll>a(n+1, 0);
        //ll b[n+1][n+1]={0};
        //a[0]=0;
        ans=n+1;
        vector<pair<ll, ll>> v;
        //ll maxi=INT_MIN;
        for(ll i=1; i<=n; i++)
        {
            cin>>some;
            v.push_back({i, some});
            //maxi=max(maxi, a[i]);
        }
        vector<pair<ll, ll>>oldv(v.begin(), v.end());

        sort(v.begin(), v.end(), byprio);
        vector<pair<ll, ll>>::iterator curr, itr;

        for(ll p=0; p<n; p++)
        {
            pair<ll, ll> old, new1;
            old.first=p+1;
            old.second=INT_MIN;
            sum=0;
            itr=upper_bound(oldv.begin(), oldv.end(), old);
            new1.second=itr->second;
            new1.first=p+1;
            curr=lower_bound(v.rbegin(), v.rend(), new1);
            //for(auto i=v.begin(); i!=v.end(); i++)
            //{
                //sum+=i->val/(i->idx-p);
             //   if(i->idx==p+1)
              //  {
              //      curr=i;
               // }
            //}
            for(auto i=v.begin(); i!=v.end(); i++)
            {i->second/(i->first-p)
                sum+=i->second/(i->first-p);
                if(sum>k)
                {
                    break;
                }
            }

            v.erase(curr, next(curr, 1));
            if(sum<=k)
            {
                ans=p+1;
                break;
            }
        }
        //for(auto i: v)
        //    cout<<i.val<<' ';
        //cout<<endl;
        cout<<ans<<endl;
    }
}
