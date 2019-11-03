/*WARNING: Brute force solution ahead!*/

#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

void rotate_right1(vector<int> &v)
{
    reverse(v.begin(), v.begin()+1);
    reverse(v.begin()+1, v.end());
    reverse(v.begin(), v.end());
}
int count1s(vector<int> &v, int k)
{
    int l=0,  temp=0;
    for(auto i: v)
    {
        if(i)
            temp++;
        else
            temp=0;
        l=max(l, temp);
    }
    return min(l, k);
}

int main()
{
	long n, q, k;
	cin>>n>>q>>k;
	vector<int> v(n);
	for(int i=0; i<n; i++)
        cin>>v[i];

	string s;//of length q
	cin>>s;

	for(char c: s)
    {
        if(c=='!')
            rotate_right1(v);
        else if(c=='?')
        {
            cout<<count1s(v, k)<<endl;
        }

    }

}
