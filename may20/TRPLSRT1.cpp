#include<bits/stdc++.h>
#define int long long
using namespace std;


class tri
{
public:
	int a, b, c;
};

int t, n, k, ar1[200001], ar2[200001], temp1, temp2, i1, i2, i3;
vector<tri> ans;
bool flag;

int getNextIdx(int i)
{
	if(i>n or i==0)
		return -1;
	while(i<=n and ar2[i]==i)
	{
		i++;
	}
	if(i<=n)
		return i;
	else
		return -1;
}

void printAns()
{
	if(ans.size()<=k)
	{
		cout<<ans.size()<<endl;
		for(auto i: ans)
			cout<<i.a<<' '<<i.b<<' '<<i.c<<endl;
	}
	else
		cout<<-1<<endl;
}

int32_t main()
{
	// freopen("in.txt", "r", stdin);
	cin>>t;
	while(t--)
	{
		flag=1;
		ans.clear();
		cin>>n>>k;
		int cnt=0;
		for(int i=1; i<=n; i++)
		{
			cin>>ar1[i];
			ar2[ar1[i]]=i;
			if(i!=ar1[i])
				cnt++;
		}
		// for(int i=1; i<=n; i++)
		// 		cout<<ar2[i]<<' ';
		if(cnt==0)
			cout<<0<<endl;
		else if(cnt==2)	
			cout<<-1<<endl;
		else
		{
			int a, b, c, d, e;
			int flag2=0, skip=0;
			// cout<<a<<' '<<b<<' '<<c<<endl;
			while(1)
			{
				a=getNextIdx(1);
				if(a==-1)
				{
					printAns();
					break;
				}
				skip=0;
				do
				{
					if(ar2[ar2[a]]!=a)
					{
						ans.push_back({ar2[ar2[a]], ar2[a], a});

						i1=ar2[ar2[a]];
						i2=ar2[a];
						i3=a;
						temp1=ar1[i1];
						ar1[i1]=ar1[i3];
						temp2=ar1[i2];
						ar1[i2]=temp1;
						ar1[i3]=temp2;
						ar2[ar1[i1]]=i1;
						ar2[ar1[i2]]=i2;
						ar2[ar1[i3]]=i3;
					}
					else if(ar2[a]!=a)
						skip++;
					a=getNextIdx(a+1);
				}
				while(a!=-1);
				if(skip==2)
				{
					cout<<-1<<endl;
					break;
				}
				else if(!skip)
				{
					printAns();
					break;
				}
				// cout<<"ehll"<<skip<<" "<<endl<<endl;
				// printAns();
				a=getNextIdx(1);
				b=getNextIdx(a+1);
				c=getNextIdx(b+1);

				if(b==ar2[a])
				{
					// ans.push_back({a, c, ar2[a]});
					ans.push_back({c, ar2[a], a});

					i1=c;
					i2=ar2[a];
					i3=a;
					temp1=ar1[i1];
					ar1[i1]=ar1[i3];
					temp2=ar1[i2];
					ar1[i2]=temp1;
					ar1[i3]=temp2;
					ar2[ar1[i1]]=i1;
					ar2[ar1[i2]]=i2;
					ar2[ar1[i3]]=i3;
					// cout<<a<<':'<<c<<':'<<ar2[a]<<endl;
					// cout<<ar2[ar1[ar2[a]]]<<' '<<ar2[ar1[a]]<<' '<<ar2[ar1[c]]<<endl;
				}
				else
				{
					ans.push_back({b, ar2[a], a});
					// cout<<a<<' '<<b<<' '<<ar2[a]<<endl;
					
					i1=b;
					i2=ar2[a];
					i3=a;
					temp1=ar1[i1];
					ar1[i1]=ar1[i3];
					temp2=ar1[i2];
					ar1[i2]=temp1;
					ar1[i3]=temp2;
					ar2[ar1[i1]]=i1;
					ar2[ar1[i2]]=i2;
					ar2[ar1[i3]]=i3;
					// cout<<a<<','<<b<<','<<ar2[a]<<endl;
					// cout<<ar2[ar1[ar2[a]]]<<' '<<ar2[ar1[a]]<<' '<<ar2[ar1[b]]<<endl;
				}
			}			
		}

	}
}
