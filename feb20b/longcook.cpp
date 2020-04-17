#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
ll m1, m2, ye1, ye2;
int days[]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int pluss[]={5, 4, 3, 2, 1, 0, 6};

bool isLeapYear(ll y)
{
	if(y%400==0)
		return true;
	if(y%100==0)
		return false;
	if(y%4==0)
		return true;
	return false;
}

int dow(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}

int dateOfSecondLastSunday(ll m, ll y)
{
	if(isLeapYear(y))
		days[1]=29;
	else
		days[1]=28;
	int wkd=dow(days[m-1], m, y);
	// cout<<wkd<<endl;
	return(days[m-1]-wkd-7);
}
int dateOfFirstFriday(ll m, ll y)
{
	int wkd=dow(1, m, y);
	return 1+pluss[wkd];
}

ll totalIntersections(ll m1, ll ye1, ll m2, ll ye2)
{
	ll cnt=0, a=dateOfFirstFriday(m1, ye1), b=dateOfSecondLastSunday(m1, ye1);
	if(a<=b && b<=a+9)
		cnt++;
	while(m1!=m2 || ye1!=ye2)
	{
		// cout<<a<<' '<<b<<endl;
		if(m1==12)
		{
			m1=1;
			ye1++;
		}
		else
			m1++;
		a=dateOfFirstFriday(m1, ye1);
		b=dateOfSecondLastSunday(m1, ye1);
		if(a<=b && b<=a+9)
			cnt++;
	}
	return cnt;

}

ll totalIntersections2(ll m1, ll ye1, ll m2, ll ye2)
{
	int s=0;
	if(m1>2) ye1++;
	if(m2==1) ye2--;
	m1=m2=2;
	int rem=(ye2-ye1+1)%28;
	s+=totalIntersections(2, ye1, 2, ye1+rem-1);
	for(int i=ye1+rem; i<=(ye2); i++)
	{
		int d=dow(1, 2, i);
		s+=(d==6 || d==0)?(1):(0);
		// cout<<i<<" "<<s<<" "<<totalIntersections(2, i, 2, i)<<endl;
	}
	return s;
}
int32_t main()
{
	// freopen("in_.txt", "r", stdin);
	// freopen("out_.txt", "w", stdout);
	// for(int i=1; i<=2000; i+=28)
	// {
	// 	cout<<dow(1, 2, i)<<", "<<totalIntersections(2, i, 2, i)<<endl;
	// }
	// for(int k=1; k<=100; k++)
	// {
	// 	int an=0, bn=0, i;
	// 	for(i=4+(k-1)*28; i<=31+(k-1)*28; i++)
	// 	{
	// 		an+=totalIntersections(2, i, 2, i);
	// 		int d=dow(1, 2, i);
	// 		bn+=(d==6 || d==0)?(1):(0);
			
	// 	}
	// 	cout<<i<<" "<<totalIntersections(2, i, 2, i)<<" "<<dow(1, 2, i)<<endl;
	// 	// cout<<an<<" "<<bn<<endl;
	// }
	// while(1);
	int t;
	cin>>t;
	while(t--)
	{
		int s=0, l;
		// cin>>m1>>ye1>>m2>>ye2;
		for(int i=1; i<=100; i++)
		{
			s=0, l=0;
			for(int j=i; j<=i+28; j++)
				s+=totalIntersections(2, j, 2, j),l+=(days[1]==29), cout<<s<<' '<<l<<endl ;
			cout<<s<<endl;
		}
		// if(ye2-ye1>=3)
		// {	
		// 	// if(m1>2) ye1++;
		// 	// if(m2==1) ye2--;
		// 	// m1=m2=2;
		// 	// int rem=(ye2-ye1+1)%28;
		// 	// for(int i=ye1; i<=(ye1+rem-1); i++)
		// 	// {
		// 	// 	int d=dow(1, 2, i);
		// 	// 	s+=(d==6 || d==0)?(1):(0);
		// 	// 	// cout<<i<<" "<<s<<" "<<totalIntersections(2, i, 2, i)<<endl;
		// 	// }
		// 	// s+=(ye2-(ye1+rem)+1)/4;
		// 	s=totalIntersections2(m1, ye1, m2, ye2);	
		// }
		// else
		// {
		// 	s=totalIntersections(m1, ye1, m2, ye2);
		// }
		cout<<s<<endl;
	}
}

