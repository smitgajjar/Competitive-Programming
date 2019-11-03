from math import gcd
t=int(input())
for _ in range(1, t + 1):
    n, l = [int(s) for s in input().split(' ')]
    k = [int(s) for s in input().split(' ')]
    idx=0
    prime=[0 for i in range(l+1)]
    i=0
    j=1
    while k[i]==k[j]:
        i+=1
        j+=1
    for ind in range(i, l+1):
        if ind==i:
            prime[ind+1]=gcd(k[ind], k[ind+1])
            prime[ind]=k[ind]//prime[ind+1]
            prime[ind+2]=k[ind+1]//prime[ind+1]
        elif ind>=i+2 and ind<=l-1:
            prime[ind+1]=k[ind]//prime[ind]
    i-=1
    while i>=0:
        prime[i]=k[i+1]//prime[i+1]
        i-=1

    cipher=prime
    primes=set(prime)
    prime=list(primes)
    prime.sort()
    dic={}
    ch=ord('A')
    for p in prime:
        dic[p]=chr(ch)
        ch+=1
    print("Case #{}: ".format(_), end='')
    for i in cipher:
        print(dic[i], end='')
    print()

            
