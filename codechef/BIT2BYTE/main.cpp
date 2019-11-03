#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        mpz_t result, result1, result2, result3, base;
        unsigned int bit=0, nibble=0, byte=0;
        scanf("%d", &n);
        unsigned long int coefficient=(n-1)/26;
        //int coefficient = 0;
        if((((n-1)%2)/2)==0)
            bit++;
        else if((((n-1)%26)/10)==0)
            nibble++;
        else if((((n-1)%26)/26)==0)
            byte++;

        mpz_inits(result, result1, result2, result3, base,NULL);
        mpz_set_str(base, "2", 10);
        mpz_pow_ui(result, base, coefficient);

        //printf("%ld %ld %ld\n", (int)(pow(2, 31)+0.5)/*(bit)*/, (long long)1<<31, ((int)(pow(2, coefficient)+0.5)*(byte)));
        if(bit==1)
        {
            mpz_out_str(stdout, 10, result);
            cout<<"0 0\n";
        }
        if(nibble==1)
        {
            cout<<"0 "
            mpz_out_str(stdout, 10, result);
            cout<<" 0\n";
        }
        if(byte==1)
        {
            cout<<"0 0 ";
            mpz_out_str(stdout, 10, result);
            cout<<"\n";
        }

        /* mpz_t result, base;
  mpz_inits(result,base,NULL);
  mpz_set_str(base, "2", 10);
  mpz_pow_ui(result, base, 20000);
  mpz_out_str(stdout, 10, result);*/
    }
}
