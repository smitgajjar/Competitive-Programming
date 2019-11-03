mod=1000000007
import matplotlib.pyplot as plt
def getsomesum(n):
    s=str(n)
    i=-1
    sum=0
    while i >= -len(s):
        val=int(s[i])
        while int(s[i])==val:
            i-=1
            if i < -len(s):
                break
        sum+=(val*10**(abs(i)-2))%mod
    return sum%mod

def getsum_modified(n):
    s=str(n)
    i=0
    temp=''
    while i < len(s):
        val=s[i]
        temp+=s[i]
        i+=1
        
        if i>len(s)-1:
            break
        
        while(s[i]==val):
            temp+='0'
            i+=1
            if i>len(s)-1:
                break
    return int(temp)%mod

def hopefully_final_getsum(s):
    f=int(s)
    n=len(s)
    final=f*(f+1)/2
    ans=0
    temp1 = s[0:n-2]
    temp2 = s[n-2:]
    print((int(temp1)*45))
    ans+=(int(temp1)*45)
    t1=int(temp2[0])
    t2=int(temp2[1])
    if t2<t1:
        print((t1-1)*t1/2)
        ans+=((t1-1)*t1/2)
    else:
        print((t1*(t1+1)/2))
        ans+=(t1*(t1+1)/2)


    temp1 = s[0:n-3]
    temp2 = s[n-3:]
    print((int(temp1)*45*100))
    ans+=(int(temp1)*45*100)
    i=int(temp2[0])
    given=int(temp2)
    p=int(temp2[2:3])
    upper=int(2*temp2[0]+(1*'9'))
    lower=int(2*temp2[0]+(1*'0'))

    if given<lower:
        print(100*i*(i-1)/2)
        ans+=100*i*(i-1)/2
    elif given > upper:
        print(100*(i)*(i+1)/2)
        ans+=100*(i)*(i+1)/2
    else:
        print(100*i*(i-1)/2+10*i*(p+1))
        ans+=100*i*(i-1)/2+10*i*(p+1)

    temp1 = s[0:n-4]
    temp2 = s[n-4:]
    print((int(temp1)*45*10000))
    ans+=(int(temp1)*45*10000)
    i=int(temp2[0])
    given=int(temp2)
    p=int(temp2[2:4])
    upper=int(2*temp2[0]+(2*'9'))
    lower=int(2*temp2[0]+(2*'0'))

    if given<lower: 
        print(10000*i*(i-1)/2)
        ans+=10000*i*(i-1)/2
    elif given > upper:
        print(10000*(i)*(i+1)/2)
        ans+=10000*(i)*(i+1)/2
    else:
        print(10000*i*(i-1)/2+100*i*(p+1))
        ans+=10000*i*(i-1)/2+100*i*(p+1)


    temp2 = s[n-5:]

    i=int(temp2[0])
    given=int(temp2)
    p=int(temp2[2:5])
    upper=int(2*temp2[0]+(3*'9'))
    lower=int(2*temp2[0]+(3*'0'))

    if given<lower: 
        print(1000000*i*(i-1)/2)
        ans+=1000000*i*(i-1)/2
    elif given > upper:
        print(1000000*(i)*(i+1)/2)
        ans+=1000000*(i)*(i+1)/2
    else:
        print(1000000*i*(i-1)/2+1000*i*(p+1))
        ans+=1000000*i*(i-1)/2+1000*i*(p+1)

    return final-ans



# x=[]
# y=[]

# print(hopefully_final_getsum(str(54321)))
# p=0
# for i in range(1, 123457):
#     p+=getsum_modified(i)
#     # x.append(i)
#     # y.append(p)
# print(p)
# x=692
# y=(((x+1)//10)*45 + ((((x+1)//10)%10)-1)*((((x+1)//10)%10)-1+1) + 100*(((x+10)//100)-1)*(((x+10)//100)-1+1)/2)
# print(x*(x+1)/2 - y)
# plt.plot(x, y)

# plt.show()

for t in range(int(input())):
    nl, l = input().split()
    nr, r = input().split()
    sum1=0
    for i in range(int(l), int(r)+1):
        sum1+=getsum_modified(i)  
    print(sum1%mod)
