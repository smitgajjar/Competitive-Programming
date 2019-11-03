#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m=1000000007;

ll mod(string n) 
{ 
    ll ans=0; 
    for (ll i=0; i<n.length(); i++) 
         ans=(ans*10+(ll)n[i]-'0')%m; 
    return ans; 
}
ll pwr(ll x, ll n) 
{ 
    ll res = 1; 
    while (n>0) 
    { 
        if (n & 1) 
            res = (res * x) % m; 
        n = n / 2; 
        x = x * x % m; 
    } 
    return res; 
}
ll power(string sa, string sb) 
{ 
    ll a = 0, b = 0; 
    for (int i = 0; i < sa.length(); i++) 
        a = (a * 10 + (sa[i] - '0')) % m; 
    for (int i = 0; i < sb.length(); i++) 
        b = (b * 10 + (sb[i] - '0')) % (m - 1);  
    return pwr(a, b); 
} 

ll modinv(int q)
{
	ll mi=m, y=0, x=1, quo, mm=m, t;
	while(q>1)
	{
		quo=q/mm;
		t=mm;
		mm=q%mm;
		q=t;
		t=y;
		y=x-quo*y;
		x=t;
	}
	if(x<0)
		x+=mi;
	return x;
}
int moreThanOrEqToU(string s)
{

	string upper;
	upper=s;
	upper[1]=upper[0];
	for(ll i=2; i<s.length(); i++)
	{
		upper[i]='9';
	}	
	for(ll i=0; i<s.length(); i++)
	{
		if(s[i]>upper[i])
			return 1;
	}
	return 0;
}

int lessThanL(string s)
{

	string lower;
	lower=s;
	lower[1]=lower[0];
	for(ll i=2; i<s.length(); i++)
	{
	 	lower[i]='0';
	}	
	for(ll i=0; i<s.length(); i++)
	{
		if(s[i]>=lower[i])
			return 0;
	}
	return 1;
}

ll get_sum(string s)
{
	string  temp;
	ll i=0;
	while(i<s.length())
	{
		ll val=s[i];
		temp+=s[i];
		i++;
		if(i>s.length()-1)
			break;
		while(s[i]==val)
		{
			temp+='0';
			i++;
			if (i>s.length()-1)
				break;
		}
		
	}
	return stoi(temp)%m;
}
ll enc(string s, ll n)
{

	if(n<4)
	{
		ll sum=0;
		for(ll i=1; i<=stoi(s); i++)
		{
			sum+=get_sum(to_string(i));
		}
		return sum%m;		
	}

	ll sub=0, d;
	string s1, s2, p;
	s1=s.substr(0, n-2);
	s2=s.substr(n-2, n);
	
	sub+=(mod(s1)*45)%m;
	///cout<<sub<<endl;

	if(s2[1]<s2[0])
	{
		sub+=((s2[0]-'0'-1)*(s2[0]-'0')*modinv(2)%m)%m;
	}
	else
	{
		sub+=((s2[0]-'0'+1)*(s2[0]-'0')*modinv(2)%m)%m;
	}
	cout<<sub<<endl;

	for(d=3; d<n;d++)
	{
		s2=s.substr(n-d, n);
		// s2=s1.back()+s2;
		s1=s.substr(0, n-d);
		// s1.pop_back();
		p=s2.substr(2, d);	
		sub+=(mod(s1)*45*pwr(10, 2*d-4))%m;
		cout<<s1<<' '<<s2<<endl;
		cout<<sub<<endl;
		int i=s2[0]-'0';
		if(lessThanL(s2))
			sub+=(pwr(10, 2*d-4)*i*(i-1)*modinv(2)%m)%m, cout<<"a";
		else if(moreThanOrEqToU(s2))
			sub+=(pwr(10, 2*d-4)*i*(i+1)*modinv(2)%m)%m, cout<<'b';
		else
			sub+=(((pwr(10, 2*d-4)*i*(i-1)*modinv(2)%m)%m+pwr(10, d-2)*i*mod(p)+pwr(10, d-2)*i)%m)%m, cout<<'c';
		cout<<sub<<endl;
	}
	s2=s.substr(n-d, n);
	// s2=s1.back()+s2;
	p=s2.substr(2, d);

	int i=s2[0]-'0';
	if(lessThanL(s2))
		sub+=(pwr(10, 2*d-4)*i*(i-1)*modinv(2))%m;
	else if(moreThanOrEqToU(s2))
		sub+=(pwr(10, 2*d-4)*i*(i+1)*modinv(2))%m;
	else
		sub+=((pwr(10, 2*d-4)*i*(i-1)*modinv(2))%m+pwr(10, d-2)*i*mod(p)+pwr(10, d-2)*i)%m;

	ll ideal=(((mod(s)*mod(s))%m+mod(s))%m*modinv(2)%m)%m;
	return(ideal-sub%m)%m;
}


ll solve(string l, ll nl, string r, ll nr)
{
	return(enc(r, nr) - enc(l, nl) + mod(to_string(get_sum(l))))%m;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll nl, nr;
		string l, r;
		cin>>nl>>l;
		cin>>nr>>r;
		cout<<solve(l, nl, r, nr)<<endl;
	}
}