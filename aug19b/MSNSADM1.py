for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    b=[int(x) for x in input().split()]
    ans=0
    r=0
    for i in range(n):
        r=(a[i]*20)-(b[i]*10)
        if(r>0 and r>ans):
            ans=r
    print(ans)
