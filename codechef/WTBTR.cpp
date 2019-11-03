//Smit Gajjar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double eu_dist(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
bool compare(const pair<ll, ll> &a,const pair<ll, ll> &b)
{
	return(a.first<b.first or ((a.first==b.first)and(a.second<b.second)));
}
bool compare2(const pair<ll, ll> &a,const pair<ll, ll> &b)
{
	return(a.second<b.second);
}
int n;
ll a,b;
double x, y, minn, minnn, distp1c1, distp2c2, distp2c1, distc1, distp1c2, distc2, c1, c2;
vector<pair<ll, ll>>pts, p;
pair<ll ,ll> myp1, myp2;

void ans(pair<ll, ll> p1, pair<ll, ll> p2)
{
	double eu_dt=eu_dist(p1, p2);
	if(eu_dt<minn)
	{
		minn=eu_dt;
		myp1=p1;
		myp2=p2;
	}

}

void near(int l, int r)
{
	if(r-l<=3)
	{
		for(int i=l; i<r; ++i)
		{
			for(int j=i+1; j<r; ++j)
			{
				ans(pts[i], pts[j]);
			}
		}
		sort(pts.begin()+l, pts.begin()+r, compare2);
		return;
	}
	int mp=(l+r)/2;
	int mid_x=pts[mp].first;
	near(l, mp);
	near(mp, r);
	merge(pts.begin()+l, pts.begin()+mp, pts.begin()+mp, pts.begin()+r, p.begin(), compare2);
	copy(p.begin(), p.begin()+r-l, pts.begin()+l);
	int cnt=0;
	for(int i=l; i<r; ++i)
	{
		if(abs(pts[i].first-mid_x)<minn)
		{
			for(int j=cnt-1; j>=0 and (pts[i].second-p[j].second<minn); --j)
			{
				ans(pts[i], p[j]);
			}
			p[cnt++]=pts[i];
		}
	}

}

int main()
{
	int t=1;
	cin>>t;
	while(t--)
	{
		minn=1000000001.0;
		pts.clear();
		cin>>n;
		p.clear();
		p.resize(n);
		for(int i=0; i<n; i++)
		{
			cin>>a>>b;
			pts.push_back({a, b});
		}
		sort(pts.begin(), pts.end(), compare);
		near(0, n);
		x=(myp1.first+myp2.first)/2.0;
		y=(myp1.second+myp2.second)/2.0;
		c1=-x+y;
		c2=-x-y;
		distp1c1=abs(myp1.first-myp1.second+c1);
		distp2c1=abs(myp2.first-myp2.second+c1);
		distc1=max(distp1c1, distp2c1);

		distp1c2=abs(myp1.first+myp1.second+c2);
		distp2c2=abs(myp2.first+myp2.second+c2);
		distc2=max(distp1c2, distp2c2);

		minnn=min(distc1, distc2);
		cout<<minnn<<endl;
		// cout<<myp1.first<<' '<<myp1.second<<endl;
		// cout<<myp2.first<<' '<<myp2.second<<endl;

	}
}
