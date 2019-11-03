#include<bits/stdc++.h>
using namespace std;
#define ll int
//sieve of eratosthenes
void sieve(ll high, vector<ll>& prime)
{
	ll n=(ll)sqrt(high);
	vector<bool> isPrime(n+1, 1);

	for(ll i=2; i*i<=n; i+=2)
	{
		if(isPrime[i])
		{
			for(ll j=i*i; j<=n; j+=i)
			{
				isPrime[j]=0;
			}
		}
	}
	for(ll i=2; i<=n; i++)
	{
		if(isPrime[i])
			prime.push_back(i);
	}

}

//segmented sieve
vector<ll> segmented_sieve(ll low, ll high)
{
	vector<ll> prime;
	vector<ll> final_primes;
	vector<ll> isPrime(high-low+1, 1);
	sieve(high, prime);//find all primes between 2 to sqrt(high) using normal sieve

	for(ll i=0; i<prime.size(); i++)
	{

		ll base=(low/prime[i])*(prime[i]);	//nearest first composite number 
										  	//which is multiple of prime[i](currrent prime)

		if(base<low)
		{
			base+=prime[i];
		}
		if(base==prime[i])
		{
			base+=prime[i];
		}
		
		for(ll j=base; j<=high; j+=prime[i])
		{
			//index 0 is mapped to low and index n-1 is mapped to high
			isPrime[j-low]=0; //numbers which are multiples of sieved primes from 2 to sqrt(high) are composite
		}
	}
	return isPrime;
}

bool isOneDigitDiff(int a, int b)
{
	string aa, bb;
	int diff=0;
	aa=to_string(a);
	bb=to_string(b);
	for(int i=0; i<4; i++)
	{
		if(aa[i]!=bb[i])
			diff++;
	}
	if(diff==1)
		return 1;
	return 0;
}
int neighbour(int pos, int node, int digit)
{
	int units=node%10; node/=10;
	int tens=node%10; node/=10;
	int hundredths=node%10; node/=10;
	int thousandths=node%10; node/=10;

	if(pos==1)
	{
		return(1000*thousandths + 100*hundredths + 10* tens + 1*digit);
	}
	if(pos==2)
	{
		return(1000*thousandths + 100*hundredths + 10* digit + 1*units);
	}
	if(pos==3)
	{
		return(1000*thousandths + 100*digit + 10* tens + 1*units);
	}
	if(pos==4)
	{
		if(digit==0)
			return node;
		return(1000*digit + 100*hundredths + 10* tens + 1*units);
	}
}
int traverse(int a, int b)
{
	vector<ll> isPrime=segmented_sieve((ll)a, (ll)b);
	queue<int> q;

	vector<bool> vis(isPrime.size(), 0);
	q.push(a);
	vis[0]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int pos=1; pos<=4; pos++)
		{
			for(int i=0; i<=9; i++)
			{

			}
		}
	}

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		cout<<traverse(a, b)<<endl;

	}

}