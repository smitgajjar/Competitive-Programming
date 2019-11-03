//Smit Gajjar
#include <bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0)
using namespace std;

int main()
{
    io;
    int t;
    cin>>t;
    while(t--)
    {
        int n, len, cnt=0;
        ll idx, val, ans=0;
        long double k;
        cin>>n>>k;
        vector<int> a(n, 0);

        for(int i=0; i<n; i++)
            cin>>a[i];
        vector<map<int, int>>v(n);
        v.clear();
        map<int, int>m;
        m.clear();
        for(int i=0; i<n; i++)
        {
            m[a[i]]++;
            v.push_back(m);
        }


        for(len=1; len<=n; len++)
        {
            val=ceil(k/len);
            idx=ceil(k/val);
            for(ll i=len-1; i<n; i++)
            {

                if(i==len-1)
                {

                    cnt=v[i][a[idx-1]];
                    if(v[i][cnt]>0)
                        ans++;

                  //  cout<<0<<ans<<endl;
                }
                else
                {
                    //val=ceil(k/len);
                    //idx=(ceil(k/val)+i-1);
                    cnt=(v[i][a[i-len+idx]]-v[i-len][a[i-len+idx]]);
                    if((v[i][cnt]-v[i-len][cnt])>0)
                        ans++;
                    //cout<<"hi"<<ans<<' '<<i-len+idx<<endl;
                }
            }
            //cout<<ans<<' '<<len<<endl;
        }
        cout<<ans<<endl;


        //cout<<v[0][3]<<endl;

        //for(auto i: v)
        //{
       //     for(auto j: i)
         //   {
           //     cout<<j.first<<' '<<j.second<<endl;
          //  }
           // cout<<"!\n";
        //}


    }
}
