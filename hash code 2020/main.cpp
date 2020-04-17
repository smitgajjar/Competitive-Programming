#include<bits/stdc++.h>
#define ll long long
using namespace std;

string in_file[]={"a_example.txt", "b_read_on.txt", "c_incunabula.txt", "d_tough_choices.txt", "e_so_many_books.txt","f_libraries_of_the_world.txt"};
FILE *out;


ll books, lib, days;
ll nbooksinlib[100001], signdaysinlib[100001], booksperdayinlib[100001];
ll score[100001];
ll temp;
vector<vector<ll>> idinlib(100001);
vector<ll> libsorted_signupday;
vector<bool> isBookIdScanned(100001);
vector<ll>lastDayForSignupLib(100001);
ll bookScannedByLib[100001];
vector<vector<ll>> libbooks_ans(100001);
int totalLib;

bool compareScore(ll a, ll b)
{
	return score[a]>score[b];
}
bool compareSignupday(ll a, ll b)
{
	// if(signdaysinlib[a] == signdaysinlib[b])
	// {
	// 	if(idinlib[a][0]<idinlib[b][0])
	// 		return signdaysinlib[a]==signdaysinlib[b];
	// }
	return signdaysinlib[a]<signdaysinlib[b];
}
void read()
{
	cin>>books>>lib>>days;
	for(int i=0; i<books; i++)
	{
		cin>>score[i];
		isBookIdScanned[i]=0;
		bookScannedByLib[i]=-1;
	}
	
	libsorted_signupday.clear();

	for(int i=0; i<lib; i++)
	{

		libsorted_signupday.push_back(i);
		libbooks_ans[i].clear();
		cin>>nbooksinlib[i]>>signdaysinlib[i]>>booksperdayinlib[i];
		idinlib[i].clear();

		lastDayForSignupLib[i]=signdaysinlib[i];

		for(int j=0; j<nbooksinlib[i]; j++)
		{
			cin>>temp;
			idinlib[i].push_back(temp);
		}
		sort(idinlib[i].begin(), idinlib[i].end(), compareScore);
		// for(auto k: idinlib[i])
		// 	cout<<k<<' ';
		// cout<<endl;
	}
}
void print()
{
	fprintf(out, "%ld\n", totalLib);
	for(int i=0; i<lib; i++)
	{
		if(libbooks_ans[libsorted_signupday[i]].size()!=0)
		{	
			fprintf(out, "%d %d\n", libsorted_signupday[i], libbooks_ans[libsorted_signupday[i]].size());
			for(int j=0; j<libbooks_ans[libsorted_signupday[i]].size(); j++)
				fprintf(out, "%d ", libbooks_ans[libsorted_signupday[i]][j]);
			fprintf(out, "\n");
		}

	}
	fclose(out);
}

void solve()
{
	sort(libsorted_signupday.begin(), libsorted_signupday.end(), compareSignupday);
	for(int i=1; i<lib; i++)
	{
		lastDayForSignupLib[libsorted_signupday[i]]+=lastDayForSignupLib[libsorted_signupday[i-1]];
	}
	ll k=0, idx[lib]={0};

	for(int day=1; day<=days; day++)
	{
		for(ll j: libsorted_signupday)
		{
			if(day>lastDayForSignupLib[j])
			{
				if(idx[j]<idinlib[j].size())
				{
					for(int pr=0; pr<booksperdayinlib[j]; pr++)
					{
						if(idx[j]<idinlib[j].size())
						{
							if(!isBookIdScanned[idinlib[j][idx[j]]])
							{
								isBookIdScanned[idinlib[j][idx[j]]]=1;
								bookScannedByLib[idinlib[j][idx[j]]]=j;
								idx[j]++;
							}
							else
							{
								idx[j]++;
								pr--;
							}
						}

					}
				}	
			}
		}
	}
	for(int i=0; i<books; i++)
	{
		if(bookScannedByLib[i]!=-1)
			libbooks_ans[bookScannedByLib[i]].push_back(i);
	}
	totalLib=0;
	for(int i=0; i<lib; i++)
	{
		if(libbooks_ans[i].size()!=0)
			totalLib++;
		for(auto j : libbooks_ans[i])
			cout<<j<<" ";
		cout<<endl;
	}
}
int main()
{
	for(int i=0; i<=5; i++)
	{
		string in_path="input/"+in_file[i];
		string out_path="output/"+in_file[i];
		freopen(in_path.c_str(), "r", stdin);
		out=fopen(out_path.c_str(), "w");
		read();
		solve();
		print();
		
		cout<<in_file[i]<<endl;

	}
}