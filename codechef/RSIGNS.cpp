#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int digits(ll n, ll k)
{
	bool flag[10]={0};
	int  digit=0 ,temp=n;
	while(temp>9)
	{
		flag[temp%10]=1;
		temp/=10;
	}
	flag[temp]=1;
	
	temp=pow(10, k)-n-1;
	
	
	while(temp>9)
	{
		flag[temp%10]=1;
		temp/=10;
	}
	flag[temp]=1;


	for(bool i: flag)
	{
			digit+=i;
	}

	return digit;
}

ll mypo(ll a, ll b) 
{ 
    ll res = 1;
  
    a = a % mod; 
    while (b > 0) 
    { 
        if (b & 1) 
            res = (res*a) % mod; 
        b = b>>1;
        a = (a*a) % mod;   
    } 
    return res; 
} 


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{	
		//Brute-force
		// ll k=6, cnt=0;

		// for(ll j=1; j<=k; j++)
		// {
		// 	cnt=0;
		// 	for(ll i=0; i<=pow(10, j)-1; i++)
		// 	{
		// 		if(digits(i, j)==2)
		// 		{
		// 			cout<<"    "<<i<<' '<<pow(10, j)-i-1<<endl;
		// 			cnt++;
		// 		}
		// 	}
		// 	cout<<j<<' '<<cnt<<endl;
		// }
		ll k;
		cin>>k;
		cout<<(mypo(2, k-1)*10)%mod<<endl;
	}
}