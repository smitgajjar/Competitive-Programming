#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m1, m2, ye1, ye2;
int days[]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int pluss[]={5, 4, 3, 2, 1, 0, 6};

bool isLeapYear(ll y)
{
	if(y%100==0 && y%400==0)
		return true;
	else if(y%100!=0 && y%4==0)
		return true;
	return false;
}

int dow(ll d, ll m, ll y) 
{ 
	ll arr[]={ 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	y -= m < 3; 
	return ( y + y / 4 - y / 100 + y / 400 + arr[m - 1] + d)%7; 
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


int main()
{
	while(1)
	{
		cout<<dow(1, 1, 1);
	}
	// freopen("in_.txt", "r", stdin);
	freopen("out_.txt", "w", stdout);
	// int t;
	// cin>>t;
	// while(t--)
	// {
	// 	cin>>m1>>ye1>>m2>>ye2;
	// 	cout<<totalIntersections(m1, ye1, m2, ye2)<<endl;
	// }
	int s;
	for(int k=0; k<=10; k++)
	{
		
		cout<<"int ans[28]={";
		for(int i=1+k*28; i<=28+k*28; i++)
		{
			// cout<<"{";
			s=0;
			for(int j=1;  j<=12; j++)
			{
				s+=totalIntersections(j, i, j, i);
				// if(j!=12)
				// 	cout<<", ";
			}
			if(i==28+k)
			cout<<s<<", ";
			// cout<<"},\n";

		}
		cout<<"};\n";
	}

	cout<<"\nint ans[28]={";
	for(int i=2017; i<=2044; i++)
	{
		// cout<<"{";
		s=0;
		for(int j=1;  j<=12; j++)
		{
			s+=totalIntersections(j, i, j, i);
			// if(j!=12)
			// 	cout<<", ";
		}
		cout<<s<<", ";
		// cout<<"},\n";
	}
	cout<<"};";
	// int t;
	// cin>>t;
	// while(t--)
	// {
	// 	cin>>m1>>ye1>>m2>>ye2;
	// 	cout<<totalIntersections(m1, ye1, m2, ye2);
		// int s=0;
		// if(ye2-ye1<=3)
		// {
		// 	s=totalIntersections(m1, ye1, m2, ye2);
		// 	// if(ye1==ye2 && m1==m2)
		// 	// 	s=totalIntersections(m1, ye1, m2, ye2);
		// 	// while(ye1!=ye2 || m1!=m2)
		// 	// {
		// 	// 	s+=totalIntersections(m1, ye1, m1, ye1);
		// 	// 	if(m1==12)
		// 	// 	{
		// 	// 		m1=1;
		// 	// 		ye1++;
		// 	// 	}
		// 	// 	else
		// 	// 		m1++;
		// 	// }
		// 	// cout<<"hiih";
		// }
		// else
		// {
		// 	while(m1!=1)
		// 	{
		// 		s+=totalIntersections(m1, ye1, m1, ye1);
		// 		if(m1==12)
		// 		{
		// 			m1=1;
		// 			ye1++;
		// 		}
		// 		else
		// 			m1++;
		// 	}
		// 	while(m2!=12)
		// 	{
		// 		s+=totalIntersections(m2, ye2, m2, ye2);
		// 		if(m2==1)
		// 		{
		// 			m2=12;
		// 			ye2--;
		// 		}
		// 		else
		// 			m2--;	
		// 	}
		// 	s+=totalIntersections(1, ye1, 12, ye1+(ye2-ye1+1)%28-1);
		// 	s+=(ye2-(ye1-1+(ye2-ye1+1)%28)+1)/4;
		// }
		// cout<<s<<endl;
	
	}

// }