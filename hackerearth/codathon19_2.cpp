#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		int a[1000]; //array will have the capacity to store 1000 digits.
    	int n,i,j,temp,m,x;
		long long p;
		cin>>p;
		string stri;

		n=p-1;// n is the power.
       a[0]=1;  //initializes array with only 1 digit, the digit 1.
       m=1;    // initializes digit counter
       i=2;// i is base 2
       int k=1;//k is a counter that goes from 1 to  n.
       temp = 0; //Initializes carry variable to 0.
       while(k<=n)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp; //x contains the digit by digit product
               a[j]=x%10; //Contains the digit to store in position j
               temp = x/10; //Contains the carry value that will be stored on later indexes
            }
             while(temp>0) //while loop that will store the carry value on array.
             { 
               a[m]=temp%10;
               temp = temp/10;
               m++; // increments digit counter
             }
             k++;
      }
              for(i=m-1;i>=0;i--) //printing answer
              	stri+=to_string(a[i]);
              long long int st=stoll(stri);

		cout<<((p%MOD)*(st%MOD))%MOD<<endl;
	}
}