#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int countletters(long long n)
{
	long long count;
	count=n/50;
	n%=50;
	count+=(n/10);
	n%=10;
	count+=(n/5);
	n%=5;
	count+=(n/1);
	return count;
}
int main()
{
	int a[MAX];

	for(long long i=1; i<MAX; i++)
	{
		a[i]=countletters(i);
	}
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=1; i<=40; i++)
	{
		cout<<i<<" "<<count(a, a+MAX-1, i)<<endl;
	}
}