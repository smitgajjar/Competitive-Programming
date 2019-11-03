t=int(input())
for __ in range(t):
    n,p=[int(i) for i in input().split()]
    m=n%(n//2+1)
    if(m==0):
        print(p**3)
    else:
        print((p-m)*(p-m)+(p-n)*(p-m)+(p-n)*(p-n))
