#include <bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ld d00, d01, d11, d10;
        ll xl, yl, xu, yu, a;
        bool corr;
        cout<<"Q 0 0"<<endl;
        cin>>d00;
        cout<<"Q 0 1000000000"<<endl;
        cin>>d01;
        cout<<"Q 1000000000 1000000000"<<endl;
        cin>>d11;
        cout<<"Q 1000000000 0"<<endl;
        cin>>d10;

        cout<<"Q 0 "<<floor((d00-d01+1000000000)/2)<<endl;
        cin>>xl;
        yl=d00-xl;

        cout<<"Q 1000000000 "<<floor((1000000000-d11+d10)/2)<<endl;
        cin>>a;
        yu=(1000000000-a);
        xu=2000000000-d11-yu;

        //yu=xl-d01+1000000000;
        //xu=2000000000-d11-yu;
        cout<<"A "<<xl<<' '<<yl<<' '<<xu<<' '<<yu<<endl;
        cin>>corr;
    }
}
