 #include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin>>n;
	
	/* 
	brute force program to find pattern of max and min permutation:
	vector<int> a(n);
	map<vector<int>, int> mapp;
	int j;
	int t=2000000;
	while(t--)
	{
		for(int i=0; i<n; i++)
			a[i]=i+1;
		

		for(int i=0; i<n; i++)
		{
			j=(rnd()%n);
			swap(a[i], a[j]);
		}
		mapp[a]++;

	}
	vector<int> max_a, min_a;
	int assumed_max=0, assumed_min=10000000;

	for(auto i: mapp)
	{
		if(i.second>assumed_max)
		{
			assumed_max=i.second; 
			max_a=i.first;
		}
		if(i.second<assumed_min)
		{
			assumed_min=i.second;
			min_a=i.first;
		}
	}

	for(int i: max_a) cout<<i<<" ";
		cout<<endl;
	for(int i: min_a) cout<<i<<" ";
		cout<<endl;
	*/
	if(n==1)
		cout<<"1\n1\n";
	else
	{
		for(int i=2; i<=(n+1)/2; i++)
			cout<<i<<" ";
		cout<<"1 ";
		for(int i=(n+1)/2+2; i<=n; i++)
			cout<<i<<" ";
		cout<<((n+1)/2+1);



		cout<<endl<<n<<" ";
		for(int i=1;i<n; i++)
		{
			cout<<i;
			if(i!=n-1)
				cout<<" ";
		}
		cout<<endl;
	}

}
