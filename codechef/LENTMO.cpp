#include<bits/stdc++.h>
#define debug(s) cout<<s<<endl<<endl;
using namespace std;
typedef long long ll;

ll x;

bool comInc(ll a, ll b)
{
	return (((a^x)-a)>((b^x)-b));

}
bool comDec(ll a, ll b)
{
	return((a-(a^x))<(b-(b^x)));
}

// bool compare(ll a, ll b)
// {
// 	if((a^x)>(b^x))
// 		return a<b;
// 	else if((a^x)<(b^x))
// 		return a>b;
// 	else
// 	{
// 		return a<b;	
// 	} 
// //	return ((a^x)>(b^x))?(a<b):(a>b);
// }
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n;
		vector<ll>a(n, 0);
		vector<ll>inc;
		vector<ll>dec;
		// map<ll, bool>mp;
		// chose<ll, bool>
		for(ll i=0; i<n; i++)
		{
			cin>>a[i];
		}
		cin>>k>>x;
		for(ll i=0; i<n; i++)
		{
			if((a[i]^x)>a[i])
				inc.push_back(a[i]);
			else
				dec.push_back(a[i]);
		}
		ll sum=0;
		
		if(inc.size()!=0)
			sort(inc.begin(), inc.end(), comInc);
		if(dec.size()!=0)
			sort(dec.begin(), dec.end(), comDec);
		//case:1 only incrementer exists
		if(dec.size()==0)
		{
			ll p=inc.size()/k;
			ll rem=inc.size()%k;
			ll to_inc=0, to_dec=0;
			for(ll i=0; i<p*k; i++)
			{
				sum+=(inc[i]^x);
			}
			for(ll i=p*k; i<inc.size(); i++)
			{
				to_inc+=((inc[i]^x)-inc[i]);//amt to be increased
			}
			for(ll i=p*k-1; i>=p*k-(k-rem); i--)
			{
				to_dec+=((inc[i]^x)-inc[i]);//amt to be decreased
			}
			if(to_inc-to_dec>0)
				sum+=(to_inc-to_dec);			
		}
		//case:2 only decrementer exits
		else if(inc.size()==0)
		{
			for(ll i=0; i<n; i++)
			{
				sum+=a[i];
			}
		}
		//case:3 both exits
		else
		{
			// debug("Hi");
			ll p=inc.size()/k;
			ll rem=inc.size()%k;
			if(rem==0)//or p==1
			{
				for(ll i=0; i<inc.size(); i++)
					sum+=(inc[i]^x);
				for(ll i=0; i<dec.size(); i++)
					sum+=(dec[i]);
			}
			else if(p==0)
			{
				ll to_inc_inc=0, to_dec_dec=0;
				for(ll i=0; i<inc.size(); i++)
				{
					to_inc_inc+=((inc[i]^x)-inc[i]);
				}
				for(ll i=0; i<(k-inc.size()); i++)
				{
					to_dec_dec+=(dec[i]-(dec[i]^x));
				}
				
				ll resultant_inc=(to_inc_inc - to_dec_dec);
				
				for(ll i=0; i<n; i++)
				{
					sum+=a[i];
				}
				if(resultant_inc>0)
				{
					
					sum+=resultant_inc;
				}
			}
			else//size of p is greater than k and has some remainder
			{
				// debug("ho");
				ll to_inc_inc=0, to_dec_inc=0, to_dec_dec=0;
				for(ll i=0; i<p*k; i++)
				{
					sum+=(inc[i]^x);
				}
				for(ll i=p*k;i<inc.size(); i++)
				{
					to_inc_inc+=((inc[i]^x)-inc[i]);
				}
				for(ll i=p*k-1; i>=p*k-(k-rem); i--)
				{
					to_dec_inc+=((inc[i]^x)-inc[i]);
				}
				if(dec.size()>=(k-rem))
				{
					// debug("ji");
					for(ll i=0; i<k-rem; i++)
					{
						to_dec_dec+=(dec[i]-(dec[i]^x));
					}
					// debug("hA");
					ll resultant_inc_ii=(to_inc_inc - to_dec_inc), resultant_inc_id=(to_inc_inc - to_dec_dec);
					if(resultant_inc_ii>0 and resultant_inc_id>0)
					{
						if(resultant_inc_ii>resultant_inc_id)
						{
							sum+=resultant_inc_ii;
							for(ll i=0; i<dec.size(); i++)
								sum+=dec[i];
						}
						else
						{
							sum+=resultant_inc_id;
							for(ll i=k-rem; i<dec.size(); i++)
							{
								sum+=dec[i];
							}
						}
					}
					else if(resultant_inc_ii>0)
					{
						sum+=resultant_inc_ii;
						for(ll i=0; i<dec.size(); i++)
							sum+=dec[i];
					}
					else if(resultant_inc_id>0)
					{
						sum+=resultant_inc_id;
						for(ll i=k-rem; i<dec.size(); i++)
						{
							sum+=dec[i];
						}
					}
					else
					{
						for(ll i=p*k; i<inc.size(); i++)
							sum+=inc[i];
						for(ll i=0; i<dec.size(); i++)
							sum+=dec[i];
					}
				}
	
				else
				{
					ll resultant_inc_ii=(to_inc_inc - to_dec_inc);
					if(resultant_inc_ii>0)
					{
						sum+=resultant_inc_ii;
						for(ll i=0; i<dec.size(); i++)
							sum+=dec[i];
					}

				}

			}
		}
		cout<<sum<<endl;


		//vector<ll>temp_dec(dec. begin(), dec.end());
		

		// ll p=(inc.size()/k);
		// ll rem=inc.size()%k;
		
		// ll rem_sum_inc=0, rem_sum_dec=0;
		// bool flag=0;
		// if(rem!=0)
		// {
		// 	for(ll i=k*p; i<inc.size(); i++)
		// 		rem_sum_inc+=((inc[i]^x)-inc[i]);
		// 	for(ll i=0; i<k-rem; i++)
		// 		rem_sum_dec+=(dec[i]-(dec[i]^x));

			
		// 	ll resultant=rem_sum_inc - rem_sum_dec;
		// 	if(resultant>0)
		// 		flag=1;
		// }
		// else
		// {
		// 	flag=0;
		// }
		// ll sum=0;
	
		// for(ll i=0; i<k*p; i++)
		// 	sum+=(inc[i]^x);
		// if(flag)
		// {
		// 	for(ll i=k*p; i<inc.size(); i++)
		// 		sum+=((inc[i]^x));
		// 	for(ll i=0; i<k-rem; i++)
		// 		sum+=((dec[i]^x));
		// 	for(ll i=k-rem; i<dec.size(); i++)
		// 		sum+=dec[i];
		// }
		// else
		// {
		// 	for(ll i=k*p; i<inc.size(); i++)
		// 		sum+=inc[i];
		// 	for(ll i=0; i<dec.size(); i++)
		// 		sum+=dec[i];
		// }
		//cout<<sum<<endl;
		// cout<<resultant<<endl;
		for (auto i: inc)
			cout<<i<<' '<<(i^x)<<((i^x)-i)<<endl;
		cout<<endl;
		for (auto i: dec)
			cout<<i<<' '<<(i^x)<<(i-(i^x))<<endl;
		// sort(a.begin(), a.end(), compare);
		// for(auto i: a)
		// 	mp[i]=((i^x)>i)?(1):(0);
			//cout<<i<<' ';
		//cout<<endl;

	}
}