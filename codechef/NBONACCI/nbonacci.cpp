#include <iostream>
#define ll long long
using namespace std;

int main() {
	
	// your code goes here
    ll n, q, f, temp, k, i;
    cin>>n>>q;
    ll a[n+1]={0};    
    for(i=0; i<n;i++)
    {
        cin>>f;
        if(i==0)
            a[i]=f;
        else
            a[i]=f^temp;
        temp=a[i];
    }
    a[i]=0;
    for(ll i=0; i<q; i++)
    {
        cin>>k;
        cout<<a[(k-1)%(n+1)]<<endl;
    }
	return 0;
}
