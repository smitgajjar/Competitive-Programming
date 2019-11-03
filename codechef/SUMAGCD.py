from math import *
t=int(input())
for _ in range(t):
    n=int(input())
    a=[int(i) for i in input().split()]
    mp={}
    for i in range(len(a)):
        if a[i] not in mp:
            mp[a[i]]=1
        else:
            mp[a[i]]=mp[a[i]]+1
    ans=0
    if len(mp)==2:
        for i in mp:
            ans+=i
    elif len(mp)==1:
        ans=a[0]*2
    else:
        p=max(a)
        q=0
        ans1=0
        ans2=0
        for i in a:
            if i!=p and i>q:
                q=i

        flag=0
        for i in a:
            if i!=p:
                if flag:
                    gcdpelse=gcd(i, gcdpelse)
                else:
                    gcdpelse=i
                    flag=1
        ans1=gcdpelse+p
        flag=0
        for i in a:
            if i!=q:
                if flag:
                    gcdqelse=gcd(i, gcdqelse)
                else:
                    gcdqelse=i
                    flag=1
        ans2=gcdqelse+q
        ans=max(ans1, ans2)        
    print(ans)
