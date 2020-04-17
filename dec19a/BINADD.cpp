#include<bits/stdc++.h>
using namespace std;
// #define int long long
string a, b;

int add(int a, int b)
{
	int carry,c=0;
	while(b)
	{

		carry=a&b;
		a=a^b;
		b=carry<<1;
		c++;
	}
	return c;
}
// auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
// std::mt19937 mt(seed);

// int myrand(int mod) {
//     return mt()%mod;
// }

int add_efficient(string a, string b, int n)
{
	bool flag=0;
	int ans=0;
	int len=0;
	for(int i=n-1; i>=0; i--)
	{
		if(a[i]=='1' and b[i]=='1')
		{
			flag=1;
			len=0;
		}
		else if((a[i]-'0')^(b[i]-'0') and flag)
		{
			len++;
		}
		else if(flag)
		{
			len++;
			ans=max(ans, len);
			len=0;
			flag=0;
		}
		else
		{
			len=0;
			flag=0;
		}
		ans=max(ans, len);
		// cout<<len<<endl;
	}
	if(flag)
		ans+=2;
	return ans;
}

int add_efficient2(string a, string b, int n)
{
	bool flag=0;
	int ans=0;
	int len=0;


	bool cy=0;
	for(int i=n-1; i>=0; i--)
	{
		if(a[i]=='1' and b[i]=='1')
		{
			cy=1;
			len=1;
		}
		else if((a[i]-'0')^(b[i]-'0'))
		{
			if(cy==1)
			{
				len++;
				cy=1;
			}
			else
			{
				len=0;
				cy=0;
			}
		}
		else
		{
			len=0;
			cy=0;
		}
		ans=max(ans, len);
	}
	ans+=1;
	return ans;
}

int add_brute(string a, string b, int n)
{
	string carry, ans;
	string aa;
	int c=0, l;
	int cy_ones=0;
	for(auto i: b)
	{
		if(i=='1') cy_ones++;
	}
	while(cy_ones)
	{
		cy_ones=0;
		carry='0';
		l=0;
		aa.clear();
		for(int i=n-1; i>=0; i--)
		{
			if((a[i]-'0')&(b[i]-'0'))
			{
				cy_ones++;
				carry='1'+carry;
				if(i==0)
				l++;
			}
			else
			{
				if(i!=0)
				carry='0'+carry;	
			}

			if((a[i]-'0')^(b[i]-'0'))
			{
				aa='1'+aa;
			}
			else
			{
				aa='0'+aa;
			}
		}
		if(l)
		{
			n++;
			a='0'+aa;
		}
		else
		{
			a=aa;
		}
		b=carry;
		c++;
		// cout<<a<<' '<<b<<endl;

	}
	return c;

}
int32_t main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a=="0" and b!="0")
			cout<<1<<endl;
		else if(b=="0")
			cout<<0<<endl;
		else
		{
			int na=a.length(), nb=b.length();
			int n=max(na, nb);
			
			for(int i=0; i<(n-na); i++)
				a='0'+a;
		
			for(int i=0; i<(n-nb); i++)
				b='0'+b;
			
			// if(add_brute(a, b, n)!=add_efficient2(a, b, n))
			// cout<<t<<' '<<add_brute(a, b, n)<<' '<<add_efficient2(a, b, n)<<endl;
			
			cout<<add_efficient2(a, b, n)<<endl;
			// for(int i=0; i<100; i++)
			// cout<<add(myrand(100000000), myrand(100000000))<<endl;	
		}


		
	}
}	