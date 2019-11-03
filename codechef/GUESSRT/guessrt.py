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

t=int(input())
for _ in range(t):
    ans=0
    flag=0
    n, k, m = [int(x) for x in input().split()]
    if m is 1:
        ans=modi(n)
        print(ans)        
    else:
        while m>0:
            
            if m is 1:
                ans+=Fraction(1, n)*(1-Fraction(1, prev_n))
                
            else:
                if n/k > 1:
                    n%=k            
                else:
                    if flag is 0:
                        ans+=Fraction(1, n)
                        flag=1
                    else:
                        ans+=Fraction(1, n)*(1-Fraction(1, prev_n))
                    prev_n=n
                    n+=k
            m-=1      
        a=ans.numerator*modi(ans.denominator)
        print(ans)
        print(a)
    
              
        
