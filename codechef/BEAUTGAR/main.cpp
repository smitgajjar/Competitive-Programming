#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        string s;
        cin>>s;
        if(*s.begin()==(*s.end()-1))
        {
            char a=*s.begin();
            for(std::string::iterator i=s.begin(); i!=(s.end()-1); i++)
            {
                *i=*(i+1);
            }
            *(s.end()-1)=a;
            cout<<a;

        }
        cout<<s;
    }
}
