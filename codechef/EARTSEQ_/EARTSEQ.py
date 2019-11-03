size = 611960
isprime = [True] * size  
primes = []  
b = [None] * (size)    
def seive(N):
    isprime[0] = isprime[1] = False  
    for i in range(2, N):
        if isprime[i] == True:          
            primes.append(i)
            b[i] = i  
          
        j = 0
        while (j < len(primes) and
               i * primes[j] < N and
                   primes[j] <= b[i]): 
            isprime[i * primes[j]] = False
            b[i * primes[j]] = primes[j] 
              
            j += 1
            
      

t=int(input())

seive(611954)
for __ in range(t):
    n=int(input())    
    a=[]
    print(len(primes))
    for i in range(n-1):
        a.append(primes[i]*primes[i+1])
        if(a[i]>1000000000):
            print(i, end="!!!!!!!!!!!!!!!!!!!!")
            break
    a.append(2*primes[n-1])
    
    for b in range(n-1):
        print(a[b], end=" ")
    print(a[n-1])
