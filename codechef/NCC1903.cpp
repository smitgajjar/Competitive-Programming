#include<iostream>
#define endl '\n'
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n>>k;
        long long sum=0, ans=0;
        int page;
        for(int i=0; i<k; i++)
        {
            cin>>page;
            sum+=page;
            if(sum<=n)
                ans++;
        }
        cout<<ans<<endl;
    }
}
