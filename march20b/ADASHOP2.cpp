#include<bits/stdc++.h>
#define endl '\n'
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;
int a[18][2]={
	{8,8},{2,2},
	{1,3},{6,8},{2,4},
	{1,5},{4,8},{2,6},
	{1,7},{2,8},
	{8,2},{7,1},
	{6,2},{5,1},{8,4},
	{7,5},{8,6},{3,1}
};
int t, r, c, diag;
int main() {
	fio;
	cin>>t;
	while(t--) {
		cin>>r>>c;
		diag=(r+c)/2;
		if(r==c and r!=1) {
			cout<<19<<endl;
			cout<<1<<' '<<1<<endl;
		}
		else if(r!=c) {
			cout<<20<<endl;
			cout<<diag<<' '<<diag<<endl;
			cout<<1<<' '<<1<<endl;
		}
		else {
			cout<<18<<endl;
		}
	
		for(int i=0; i<18; i++) {
			cout<<a[i][0]<<' '<<a[i][1]<<endl;
		}
	}
}