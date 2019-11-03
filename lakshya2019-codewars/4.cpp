//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class idx
{
public:
    ll l, r;
};
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n, k, l, r;
	    cin>>n>>k;
	    vector<ll> v(100000, 0);

	    vector<idx> op(n);

	    for(ll i=0; i<n; i++)
        {
            cin>>l>>r;
            op[i].l=l;
            op[i].r=r;
        }
        for(ll j=0; j<n; j++)
        {
            //cout<<op[j].l<<' '<<op[j].r<<endl;
            for(ll i=op[j].l-1; i<=op[j].r-1; i++)
            {
                v[i]++;
            }
        }
        //ll ans=0;
        ll ans=INT_MIN, cnt=count(v.begin(), v.end(), k), add=0, sub=0, c=0;

        for(ll j=0; j<n; j++)
        {

            sub=0, add=0;
            for(ll i=op[j].l-1;i<=op[j].r-1; i++)
            {
                if(v[i]==k)
                    sub++;
                if(v[i]==k+1)
                    add++;
            }
            //c-=count(v.begin(), v.begin(), k);
            //c+=count(v.begin(), v.begin(), k+1);
            c=cnt-sub+add;
        //    cout<<c<<"  !!!\n";
            ans=max(c, ans);
        }
        //cout<<endl<<endl;
        cout<<ans<<endl;

    }
}
