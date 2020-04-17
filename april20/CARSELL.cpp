#include<bits/stdc++.h>
using namespace std;
const int deadend = 1e9+7;
int t, n, a[100000], val, ans;

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i];
		}
		sort(a, a+n, greater<int>());
		val=0, ans=0;
		for(int i=0; i<n; i++) {
			if(a[i]!=0) {
				ans+=(a[i]-val)%deadend;
			}
			val++;
		}
		cout<<(ans%deadend)<<endl;
	}
}