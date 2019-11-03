for _ in range(int(input())):
    s=input()
    cnt1=0
    for i in s:
        if i=='1':
            cnt1+=1
    if cnt1%2==0:
        print('LOSE')
    else:
        print('WIN')
