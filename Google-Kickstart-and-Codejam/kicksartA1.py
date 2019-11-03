t=int(input())
for _ in range(t):
    n, p=[int(i) for i in input().split()]
    sarr=[int(i) for i in input().split()]
    sarr.sort(reverse=True)
    psum=[0 for x in range(n-p+1)]
    i=0
    j=0
    while(i<n-p+1):
        j=0
        while(j<i+p-1):
            psum[i]+=sarr[j+1]
            j+=1
        i+=1
    ans=10000000000
    for i in psum:
        print(i)
    for i in range(n-p+1):
        ans=min(ans, p*sarr[i]-psum[i])
        
    print("Case #", _+1,": ", ans, sep='')
