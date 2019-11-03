#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	// your code goes here
    int q;
    cin>>q;
    while(q--)
    {
        int n1, n2, num;
        ll l, r;
        cin>>l>>r>>n1>>n2;
        ll size=r-l+1;
        int mod=size%9;
        bool o=0, k=0;
        n1%=9, n2%=9;
        num=l%9;
        for(int i=1; i<=mod && i<=size; i++)
        {
            if(num==n1)
                o=1;
            if(num==n2)
                k=1;
            num++;
        }
        if((o && k) || (!o && !k))
            cout<<"Draw"<<endl;
        else
            cout<<(o?"Onkar":"Krushna")<<endl;

    }
	return 0;
}
