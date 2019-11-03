#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        vector<string>s(n);
        string str;
        for(long i=0; i<n; i++)
        {
            cin>>str;
            for(char c: str)
            {
                if(s[i].find(c)==string::npos)
                    s[i]+=c;
            }
            sort(s[i].begin(), s[i].end());

        }
        ll cnt=0;
        string st;
        map<string, ll> mp;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }
        ll k=mp["aeiou"];
        cnt=k*(2*n-k-1)/2;
        for(auto m=mp.begin(); m!=mp.end(); m++)
        {
            if(m->first!="aeiou")
            {

                for(auto p=next(m,1); p!=mp.end(); p++)
                {
                    if(p->first!="aeiou")
                    {
                        str=m->first+p->first;
                        if(str.find('a')!=string::npos && str.find('e')!=string::npos && str.find('i')!=string::npos && str.find('o')!=string::npos && str.find('u')!=string::npos )
                        {
                            cnt+=(m->second)*(p->second);
                        }
                    }

                }
            }
        }
        cout<<cnt<<endl;


    }
}
