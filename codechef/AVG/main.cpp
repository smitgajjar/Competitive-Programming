#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       ll n, k, val;
       map<ll, vector<ll>>occur;
       map<ll, vector<ll>>dist;
       cin>>n>>k;
       ll a[n];
       for(ll i=0; i<n; i++)
       {
           cin>>val;
           occur[val].push_back(i);
       }
       ll max_siz=0;
       for(auto i: occur)
       {
           for(ll j=0; j<i.second.size(); j++)
           {
               if(j!=i.second.size()-1)
                dist[i.first].push_back(i.second.at(j+1)-i.second.at(j)-1);
           }
           ll siz=i.second.size();
           max_siz=max(siz, max_siz);
       }
       if(max_siz<k)
       {
           cout<<-1<<endl;
       }
       else
       {
           ll min_sum=INT_MAX, sum=0;
           //cout<<"h\n\n\n!!!!!!!!\n";
            for(auto i: dist)
            {

                ll sizz=i.second.size()-k+1;
               for(ll j=0; j<=sizz; j++)
               {
                   sum=0;
                   for(ll p=j; p<=j+k-2; p++)
                   {
                       sum+=i.second[p];
                   }
                   //cout<<sum<<'?'<<endl;
                   min_sum=min(sum, min_sum);
               }
            }
            cout<<min_sum<<endl;
       }



    }

	return 0;
}
