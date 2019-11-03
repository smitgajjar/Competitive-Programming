from math import sqrt
import sys
def getfactor(n):
    prim=set()
    while n%2==0:
        prim.add(2)
        n//=2
    for i in range(3, int(sqrt(n))+1, 2):
        while n%i==0:
            prim.add(i)
            n//=i
    if n>2:
        prim.add(n)
    
    return prim
rem=set()
s=set()
val=0

x=31627

for _ in range(int(input())):
    x=31627
    s.clear()
    print(1, x)
    sys.stdout.flush()
    m=int(input())
    s=getfactor((x*x)-m)
    l=list(s)
    l.sort()
    last=l[-1]
    #for i in s:
    #    print(i, end=' ')
    x=last
    f=0
    for i in range(x, x+11, 1):
        rem.clear()
        for k in s:
            val=(i*i)%k
            if val in s:
                f=1
                break
            rem.add(val)
        if f==1:
            f=0
            continue

        if len(s)==len(rem):
            x=i
            f=1
            break
    print(1, x)
    sys.stdout.flush()
    m=int(input())
    ans=0
    for i in s:
        if((x*x)%i==m):
            ans=i
    print(2, ans)
    sys.stdout.flush()
    tp=input()
    if tp=="No":
        break
