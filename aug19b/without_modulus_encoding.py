mod=1000000007
import matplotlib.pyplot as plt
def modi(q, m=mod):
    mi = m 
    y = 0
    x = 1

    while (q > 1) : 
        quo = q // m 
        t = m  
        m = q % m 
        q = t 
        t = y 
        y = x - quo * y 
        x = t 
    if (x < 0) : 
        x = x + mi
    return x
mymodi2=modi(2)
def power(a, b, p=mod) : 
	r = 1
	a = a % p 

	while (b > 0) :
		if ((b & 1) == 1) : 
			r = (r * a) % p 
		b = b >> 1
		a = (a * a) % p 
		
	return r 

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


def encoding_function(s):
	f=int(s)
	n=len(s)

	if n<4:
		sum1=0
		for i in range(1,int(s)+1):
		    sum1+=(getsum_modified(i)%mod)
		return sum1%mod

	final=int(f%mod*(f+1)%mod*mymodi2)%mod
	ans=0

	temp1 = s[0:n-2]
	temp2 = s[n-2:]
	# print((int(temp1)*45))
	ans+=(int(temp1)%mod*45)%mod
	t1=int(temp2[0])
	t2=int(temp2[1])
	if t2<t1:
	    # print((t1-1)*t1/2)
	    ans+=((t1-1)%mod*t1%mod*mymodi2)%mod
	else:
	    # print((t1*(t1+1)/2))
	    ans+=((t1+1)%mod*t1%mod*mymodi2)%mod

	for d in range(3, n):
	    temp1 = s[0:n-d]
	    pp=power(10, 2*(d-2))
	    ans+=(int(temp1)%mod*45*pp)%mod

	    temp2 = s[n-d:]
	    # print((int(temp1)*45*100))
	    
	    i=int(temp2[0])
	    given=int(temp2)
	    p=int(temp2[2:d])
	    upper=int(2*temp2[0]+((d-2)*'9'))
	    lower=int(2*temp2[0]+((d-2)*'0'))

	    if given<lower:
	        # print(10**(2*(d-2))*i*(i-1)/2)
	        ans+=(pp*(i%mod)*(i-1)%mod*mymodi2)%mod
	    elif given >= upper:
	        # print(100*(i)*(i+1)/2)
	        ans+=(pp*(i%mod)*(i+1)%mod*mymodi2)%mod
	    else:
	        # print(100*i*(i-1)/2+10*i*(p+1))
	        ans+=(pp*(i%mod)*(i-1)%mod*mymodi2)%mod+power(10, d-2)i%mod*(p+1)%mod

	d+=1
	temp2 = s[n-d:]

	i=int(temp2[0])
	given=int(temp2)
	p=int(temp2[2:d])
	upper=int(2*temp2[0]+((d-2)*'9'))
	lower=int(2*temp2[0]+((d-2)*'0'))

	if given<lower:
	    # print(10**(2*(d-2))*i*(i-1)/2)
	    ans+=(pp*i%mod*(i-1)%mod*mymodi2)%mod
	elif given >= upper:
	    # print(100*(i)*(i+1)/2)
	    ans+=(pp*i%mod*(i-1)%mod*mymodi2)%mod
	else:
	    # print(100*i*(i-1)/2+10*i*(p+1))
	    ans+=(pp*i%mod*(i-1)%mod*mymodi2)%mod
	return int(final - ans)%mod
# x=[]
# y=[]
# for i in range(1, 10000000):
# 	x.append(i%mod)
# 	y.append(encoding_function(str(i))%mod)

# plt.plot(x, y)
# plt.show()
for t in range(int(input())):
	nl, l = input().split()
	nr, r = input().split()
	ans1=encoding_function(r)
	ans2=encoding_function(str(int(l)-1))
	print((ans1-ans2)%mod)
	#print((ans2-ans1)%mod)