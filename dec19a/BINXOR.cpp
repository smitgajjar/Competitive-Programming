#include<bits/stdc++.h>
#define N 100001
#define P 1000000007
#define int long long
using namespace std;
int fac[N+1], infac[N+1];

int n;
string a, b;
int oneA, zeroA, oneB, zeroB;

int power(int base, int exponent, int mod)
{
	int ans=1;
	base%=mod;
	while(exponent > 0)
	{
		if(exponent & 1)
			ans=(ans*base)%mod;//If exponent is odd, then multiply base and answer, giving remaining even exponent
		base=(base*base)%mod;
		exponent>>=1;//
	}
	return ans%mod;
}

int modInv(int n, int p) 
{ 
    return power(n, p-2, p); 
}

void calc_fact()
{ 
    fac[0] = 1; 
    for (int i=1; i<=N; i++) 
        fac[i] = fac[i-1]*i%P;
    infac[0] = 1; 
    for (int i=1; i<=N; i++) 
        infac[i] = infac[i-1]*modInv(i, P)%P;
}

int nCr(int n, int r, int p=P) 
{
	if (r==0) 
		return 1; 
	return ((fac[n]*infac[r]%p*infac[n-r]%p)%p); 
}

int32_t main()
{
	calc_fact();
	int t;
	cin>>t;

	while(t--)
	{
		oneA=oneB=0;
		zeroA=zeroB=0;
		cin>>n>>a>>b;
		for(auto i: a)
		{
			if(i=='0') zeroA++;
			if(i=='1') oneA++;
		}
		for(auto i: b)
		{
			if(i=='0') zeroB++;
			if(i=='1') oneB++;
		}
		int mini=abs(oneA-oneB);
		int maxi=min(oneA, zeroB)+min(oneB, zeroA);
		int ans=0;

		for(int i=mini; i<=maxi; i+=2)
		{
			ans+=nCr(n, i);
			// cout<<i<<"|";
			// cout<<ans<<' ';
		}
		cout<<ans%P<<endl;
	}
	return 0;
}