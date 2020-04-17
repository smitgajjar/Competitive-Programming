#include<bits/stdc++.h>
#define endl '\n'
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int t, n, q, p, odd, even;
int a[100001];
int main() {
	fio;
	// freopen("engxor.txt", "r", stdin);
	cin>>t;
	while(t--) {
		cin>>n>>q;
		even=0, odd=0;
		for(int i=0; i<n; i++) {
			cin>>a[i]; 
			if(__builtin_popcount(a[i])&1==1)
				odd++;
			else
				even++;
		}

		while(q--) {
			cin>>p;
			bool boo=(__builtin_popcount(a[0])&1)==(__builtin_popcount(a[0]^p)&1);
			if(boo)
				cout<<even<<' '<<odd;
			else
				cout<<odd<<' '<<even;
			cout<<endl;
		}
	}
}