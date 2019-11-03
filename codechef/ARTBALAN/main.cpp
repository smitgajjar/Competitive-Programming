#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool revsort(const pair<ll, char> &a, const pair<ll, char>&b)
{
    return a.first>b.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        ll len;
        map<char, ll> emap;
        vector<pair<ll, char>> vect_rev;
        emap.clear();
        vect_rev.clear();
        cin>>s;
        len=s.length();
        if(len==1)
        {
            cout<<"0\n";
            continue;
        }
        for(ll i=0; i<s.length(); i++)
        {
            emap[s[i]]++;
        }
        ll distinct=emap.size();
        for(auto e: emap)
        {
            vect_rev.push_back({e.second, e.first});
        }
        sort(vect_rev.begin(), vect_rev.end(), revsort);

        ll ans=0;
        ll future_distinct, same, future_distinct2;
        for(ll i=1; i<=len; i++)
        {
            if(len%i==0)
            {

            if(i>distinct)
            {
                future_distinct2=i;
                break;
            }

            future_distinct=i;
            }
        }
        ll cnt=0;
        //cout<<future_distinct<<"fd"<<vect_rev.size()<<endl;
        for(auto i: vect_rev)
        {
            cnt++;
            if(cnt>future_distinct)
            {
                ans+=i.first;
                //cout<<"if"<<" "<<ans<<endl;
            }
            else
            {
                if(i.first>(len/future_distinct))
                {
                    ans+=(i.first - len/future_distinct);
                //cout<<"else\n";
                }

            }
            //cout<<cnt<<endl;
        }

        //ans=min(ans, ans1);
        ll cnt2=0, ans2=0;
        //cout<<future_distinct<<"fd"<<vect_rev.size()<<endl;
        for(auto i: vect_rev)
        {
            cnt2++;
            if(cnt2>future_distinct2)
            {
                ans2+=i.first;
                //cout<<"if"<<" "<<ans<<endl;
            }
            else
            {
                if(i.first>(len/future_distinct2))
                {
                    ans2+=(i.first - len/future_distinct2);
                //cout<<"else\n";
                }

            }
            //cout<<cnt<<endl;
        }




        if(len<26)
        {
          ans=min(len-vect_rev.begin()->first, ans);
          ans=min(ans, len-distinct);
          ans=min(ans, ans2);
        }



        cout<<ans<<endl;
    }
}

