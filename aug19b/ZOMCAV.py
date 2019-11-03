for _ in range(int(input())):
    n=int(input())
    c=[int(i) for i in input().split()]
    h=[int(i) for i in input().split()]
    h.sort()
    a=[0 for i in range(n)]
    for i in range(n):
        for j in range(max(i+1-c[i], 0), min(i+1+c[i], n)):
            a[j]+=1
    a.sort()
    flag=1
    for i in range(n):
        if a[i]!=h[i]:
            flag=0
            break
    if flag==1:
        print('YES')
    else:
        print('NO')
