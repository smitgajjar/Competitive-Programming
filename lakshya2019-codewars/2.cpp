//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	long t;
	cin>>t;
	while(t--)
	{
	    long n, a, b;
	    cin>>n;
	    long arr[n];

        for(long i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        long ans;
        bool flag=0;
        if(__gcd(arr[0], arr[1])!=1)
        {
            for(long i=1; i<n; i++)
            {
                if(arr[i]%arr[0]!=0)
                {
                flag=1;
                ans=arr[i];

                }
            }
            if(flag)
            {
                cout<<ans<<endl;
            }
            else
            {
                cout<<"COMPLETELY FINE!\n";
            }
        }
        else
        {
            long cnt=0;
            for(long i=2; i<n; i++)
            {
                if(arr[i]%arr[0]==0)
                {
                    cnt++;
                }
            }
            if(cnt==n-2)
            {
                ans=arr[1];
            }
            else
                ans=arr[0];
            cout<<ans<<endl;
        }





	}
}
