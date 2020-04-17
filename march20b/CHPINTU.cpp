#include<bits/stdc++.h>
using namespace std;

int t, n, m, curr;
int f[51];
map<int,int> mp;
int main() {
	// freopen("in.txt", "r", stdin);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		mp.clear();
		for(int i=0; i<n; i++) {
			cin>>f[i];
		}
		for(int i=0; i<n; i++) {
			cin>>curr;
			mp[f[i]]+=curr;
			// cin>>p[i];
		}
		int minn=INT_MAX, type;
		for(auto i: mp) {
			if(i.second<minn) {
				minn=i.second;
				type=i.first;
			}
		}
		cout<<minn<<endl;
	}
}