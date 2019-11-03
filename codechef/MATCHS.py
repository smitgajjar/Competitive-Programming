t=int(input())
for _ in range(t):
    n, m=[int(a) for a in input().split()]
    a=max(n, m)
    b=min(n, m)
    flag=True
    while a%b!=0 :
        if a//b>1:
            break
        else:
            a=a%b
            t=a
            a=b
            b=t
        flag=not(flag)
    if flag:
        print('Ari')
    else:
        print('Rich')
