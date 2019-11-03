from fractions import *
def modi(q, m=1000000007):
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

def mypow(base, expo, m=1000000007):
    k=1
    l=b
    while expo:
        if expo & 1:
            k=(k*l)%m
        l=(l*l)%m
        expo/=2
    return k

t=int(input())
for _ in range(t):
    ans=0
    n, k, m = [int(x) for x in input().split()]

    
    if m%2 == 1:
        ans=(1-(Fraction(n-1, n))**((m+1)//2))
    else:   
        ans=1+(Fraction(1, k+n)-1)*(1-Fraction(1, n))**(m//2)
    #print(ans)
    print(modi(117))
    print((ans.numerator%1000000007*modi(ans.denominator))%1000000007)
    
