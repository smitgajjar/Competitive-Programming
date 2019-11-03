#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        vector<char> base, ans;
        base.clear();
        //for(char c: base)
        //    cout<<c;
        int minls=201, mini;
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            if(s[i].length()<minls)
                minls=s[i].length(), mini=i;
        }
        for(char c: s[mini])
            base.push_back(c);
        for(int i=0; i<n; i++)
        {
            sort(s[i].begin(), s[i].end());
        }
        sort(base.begin(), base.end());
        set<char> base1(base.begin(), base.end());
        if(n==1)
        {
        cout<<base1.size()<<endl; continue;
        }
        map<char, int> emap;

        for(char c: base)
        {
            emap[c]++;
        }
        //map<char, int>::iterator it;
        for(auto i: emap)
        {
            char ele=i.first;
            int frq=i.second;
            bool found=1;
            for(int j=0; j<n; j++)
            {
                if(j!=mini)
                {
                    if (binary_search( s[j].begin(), s[j].end(), ele ))
                    {
                        int l = lower_bound(s[j].begin(), s[j].end(), ele) - s[j].begin();
                        int r = upper_bound(s[j].begin(), s[j].end(), ele) - s[j].begin();

                        if ((r - l) < frq)
                            frq = r - l;
                    }
                    else
                    {
                    found = false;
                    break;
                    }
                }

            }
            if(found)
            {
                //for(int i=0;i<frq;i++)
                    ans.push_back(ele);
            }
        }
        cout<<ans.size()<<endl;

    }
}
