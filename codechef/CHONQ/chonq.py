t=int(input())
for _ in range(t):
    n, k = [int(x) for x in input().split()]
    arr=[int(x) for x in input().split()]
    sum1=0
    p=1
    s=0
    ans=n+1
    while(1):
        j=n-1
        p=n-s
        sum1=0
        while(j>=s):
            sum1+=arr[j]//p
            if sum1>k:
                s=j+1
                break
            p-=1
            j-=1
        if sum1<=k:
            ans=j+2
            break
        if s>=n-1:
            break
    print(ans)
