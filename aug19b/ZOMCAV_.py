def add(a, l, r, n):
    a[l]+=1
    if r!= n-1:
        a[r+1]-=1

for _ in range(int(input())):
    n=int(input())
    c=[int(i) for i in input().split()]
    h=[int(i) for i in input().split()]
    a=[0 for i in range(n)]

    for i in range(n):
        add(a, max(i-c[i], 0), min(i+c[i], n-1), n)
        
    for i in range(1, n):
        a[i]+=a[i-1]

    flag=1
    a.sort()
    h.sort()

    for i in range(n):
        if a[i] != h[i]:
            flag=0
            break
    
    #print(a, h)
    if flag==1:
        print('YES')
    else:
        print('NO')
