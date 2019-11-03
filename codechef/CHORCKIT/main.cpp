#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


struct stringg
{
    long pri;
    long indx;
    char charr;
};
struct goo_useful
{
    long cost, indx;
    string str;
};
bool priosort(stringg i, stringg j)
{
    return i.pri<j.pri;
}
int main()
{
    long n, m, a, x, r, value;
    string s, tempstr;
    vector<pair<long, string>> pretty, good;
    vector<goo_useful> goodUseful;
    map<char, int> ch;


    int k=1;
    for(char i='a'; i<='z'; i++)
        ch.insert({i, k++});
    for(char i='A'; i<='Z'; i++)
        ch.insert({i, k++});

    cin>>n>>m>>a>>x>>r;
    cin>>s;
    vector<stringg> ss;

    for(long i=0; i<m; i++)
    {
        cin>>tempstr>>value;
        pretty.push_back({value, tempstr});
    }
    for(long i=0; i<a; i++)
    {
        cin>>tempstr>>value;
        good.push_back({value, tempstr});
    }
    char one;
    bool flag=0;
    long prev_v=0;
    for(auto c: pretty)
    {

        if(c.second.length()==1)
        {
            if(c.first>prev_v)
                one=c.second[0], flag=1, prev_v=c.first;
        }

    }



    for(long i=0; i<n; i++)
    {
        ss.push_back({abs(ch[s[i]]-ch[one]), i, s[i]});
    }

    sort(ss.begin(), ss.end(), priosort);
    /*for(auto a: ss)
    {
        cout<<a.pri<<' '<<a.indx<<' '<<a.charr<<endl;
    }
    */


    long good_useful_idx=0, good_useful_cost=100000, good_useful_length;
    long cg=0;
    string equ_pretty;

    for(auto g: good)
    {
        cg+=1;
        for(auto p: pretty)
        {
            if(p.second.find(g.second)!=string::npos)
            {
                goodUseful.push_back({g.first, cg, g.second});

                if(g.first<good_useful_cost)
                {
                    good_useful_idx=cg;
                    good_useful_length=g.second.length();
                    good_useful_cost=g.first;
                    equ_pretty=p.second;
                }


            }
        }
    }

    //cout<<good_useful_idx<<endl<<endl;


    if(flag)
    {
        vector<long> idx;
        for(auto i: ss)
        {
            if(i.charr!=one && i.pri<=(x))
            {
                x=x-i.pri;
                idx.push_back(i.indx+1);
            }
        }

        long siz=idx.size();
        if(siz==0)
            cout<<"0\n";
        else
        {

            //if(good_useful_idx==0)
                cout<<siz<<endl;
            //else
              //  cout<<siz+1<<endl;
            //cout<<3<<' '<<1<<' '<<n<<endl;
            for(auto i: idx)
            {
                cout<<1<<" "<<i<<" "<<one<<endl;
            }


            //if(good_useful_idx!=0)
                //cout<<2<<" "<<n<<" "<<n<<" "<<good_useful_idx<<endl;
            //cout<<3<<" "<<1<<" "<<n-1+good_useful_length<<endl;
        }

    }
    /*
    else if(good_useful_cost<=x)
    {
        cout<<1<<endl;
        cout<<2<<" "<<n<<" "<<n<<" "<<good_useful_idx<<endl;
    }
    */


    else if(good_useful_cost<=x)
    {
        //cout<<1<<endl;
        vector<pair<long, char>> pretty1;
        if(s.find(equ_pretty)==string::npos)
        {
            if(x>=ch[equ_pretty[0]])
            {
                k=0;
                while(x>=0 && k+1<=10000)
                {

                for(long i=0; i<equ_pretty.length() && x>=0; i++)
                {
                    x-=ch[equ_pretty[i]];
                    k+=1;
                    pretty1.push_back({k, equ_pretty[i]});
                }
                k+=4;

                }

            }
        }
        long sizz=pretty1.size();
        cout<<sizz<<endl;
        for(long i=0; i<sizz; i++)
        {
            cout<<1<<" "<<pretty1[i].first<<" "<<pretty1[i].second<<endl;
        }
        //cout<<2<<" "<<n/2<<" "<<n/2<<" "<<good_useful_idx<<endl;
    }
    else
        cout<<"0\n";

}
