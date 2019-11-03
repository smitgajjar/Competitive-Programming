    t=int(input())
    for _ in range(1, t + 1):
        n, l = [int(s) for s in input().split(' ')]
        k = [int(s) for s in input().split(' ')]
        idx=0
        prime=[]
    for j in range(len(k)):
        if j==0:       
                for p in range(2, k[j]):
                    if k[j]%p==0:
                        prime.append(p)
                        prime.append(k[j]//p)
                        idx=1
                        break
                    
        else:
            if j==1:
                
                if(k[j]%prime[idx]==0):
                    prime.append(k[j]//prime[idx])
                    idx+=1
                else:
                    prime.append(k[j]//prime[idx-1])
                    tem=prime[idx]
                    prime[idx]=prime[idx-1]
                    prime[idx-1]=tem
                    idx+=1
                    
        
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
