#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string quote;

		getline(cin, quote);
		if(quote.find(" not ")!=(string::npos) || quote.find("not ")==0 ||quote.find(" not")==(quote.length()-4))
			cout<<"Real Fancy\n";
		else
			cout<<"regularly fancy\n";
	}
	

}