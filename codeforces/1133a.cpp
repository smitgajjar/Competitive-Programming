//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s1, s2;
	cin>>s1>>s2;
	string str(s1.begin(), s1.begin()+2);
	int h1=stoi(str);
	string str2(s1.begin()+3, s1.begin()+5);
	int m1=stoi(str2);
	string str3(s2.begin(), s2.begin()+2);
	int h2=stoi(str3);
	string str4(s2.begin()+3, s2.begin()+5);
	int m2=stoi(str4);
	
	float h=((float)h1+h2)/2.0;
	int min=(m1+m2)/2;
	cout<<min<<endl;
	min+=(h-int(h))*60;
	

	if((int)h<10)
		cout<<0;	
	cout<<(int)h<<":";
	if(min<10)
		cout<<0;
	cout<<min<<endl;
}