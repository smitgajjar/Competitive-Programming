#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
	for(ll i=low; i<=high; i++)
	{
		if(isPrime[i-low])
			final_primes.push_back(i);

	}
	return final_primes;
}
int main()
{
	vector<ll> a=segmented_sieve(3, 1000);
	for(auto i: a)
		cout<<i<<' ';
	return 0;
}