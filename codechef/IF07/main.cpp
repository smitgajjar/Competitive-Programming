#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<string> s(n);
   //string ss[n][n];
   vector<int>charr(26);
   vector<int>charrr(26);
   charr.assign(26, 0);
   for(int i=0; i<n; i++)
   {
       cin>>s[i];
   }
   ll cnt=0;
   for(int i=0; i<n-1; i++)
   {
       charrr.assign(26, 0);
       for(ll j=0; j<s[i].length(); j++)
       {
           charrr[s[i][j]-'A']=1;
       }
       for(ll k=i+1; k<n; k++)
       {
           charr.assign(26, 0);
           charr=charrr;
           for(ll j=0; j<s[k].length(); j++)
           {
               if(charr[s[k][j]-'A']==1)
                    charr[s[k][j]-'A']=0;
               else
                    charr[s[k][j]-'A']=1;
           }
           if(find(charr.begin(), charr.end(), 0)==charr.end())
            cnt++;
       }
   }
   cout<<cnt<<endl;

}
