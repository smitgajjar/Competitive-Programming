def digsum(n):
    s=str(n)
    sum=0
    for i in s:
        sum+=int(i)
    return sum
for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    maxx=digsum(a[0]*a[1])
    c=0
    for i in range(n-1):
        for j in range(i+1, n):
            c=digsum(a[i]*a[j])
            if(c>maxx):
                maxx=c
    print(maxx)
