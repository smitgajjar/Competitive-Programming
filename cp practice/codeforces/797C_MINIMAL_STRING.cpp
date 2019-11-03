#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int len=a.length();
	int best[len+1];
	int s[len];
	best[len]=1e9;
	for(int i=len-1;i>=0;i--){
	    s[i]=a[i]-'a';
        best[i]=min(s[i],best[i+1]);
	}
	int q[len];
	int t=0;
	string res="";
	for(int j=0;j<len;j++)
	{
	q[t]=s[j];
	t++;
	while(t>0 && q[t-1]<=best[j+1] )printf("%c",q[t-1  ]+'a'),t--;
	 
	}
 
 
    return 0;
 
}