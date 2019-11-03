from math import *
mod=1000000007
def modi(q, m=mod):
    mi = m 
    y = 0
    x = 1

    while (q > 1) : 
        quo = q // m 
        t = m  
        m = q % m 
        q = t 
        t = y 
        y = x - quo * y 
        x = t 
    if (x < 0) : 
        x = x + mi
    return x
t=int(input())

for _ in range(t):
    n, k=[int(i) for i in input().split()]
    D=-(n-1)
    A=k-1
    N=((D-A)//D)
    #print(N, A+(ceil(N)-1)*D)
    #ans=int((N%mod/2)*(2*A+(N-1)*D))
    ans=(((-(n*N*N)%mod + ((N%mod)*(N%mod))%mod + ((n%mod)*(N%mod))%mod - 3*(N%mod) + 2*((N%mod)*(k%mod))%mod)%mod)*(modi(2)%mod))%mod
    print(int(ans))
