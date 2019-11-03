import random
mod=1000000007
# import matplotlib.pyplot as plt
def modf(s):
	ans=0
	for i in range(len(s)):
		ans=(ans*10+int(s[i]))%mod
	return ans

def modinv(q, m=mod):
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

def power(a, b, p) : 
	r = 1
	a = a % p 

	while (b > 0) :
		if ((b & 1) == 1) : 
			r = (r * a) % p 
		b = b >> 1
		a = (a * a) % p
	return r

def moreOrEqToUpper(given, upper, d):
	for i in range(d):
		if given[i]>upper[i]:
			return True
	return False

def lessThanLower(given, lower, d):
	for i in range(d):
		if given[i]>=lower[i]:
			return False
	return True

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
		    sum1+=(getsum_modified(i))
		return sum1%mod
	
	final=int(f*(f+1)//2)
	ans=0

	temp1 = s[0:n-2]
	temp2 = s[n-2:]
	# print((int(temp1)*45))
	ans+=(int(temp1)*45)
	print(ans%mod)
	t1=int(temp2[0])
	t2=int(temp2[1])
	if t2<t1:
	    # print((t1-1)*t1/2)
	    ans+=((t1-1)*t1//2)
	else:
	    # print((t1*(t1+1)/2))
	    ans+=(t1*(t1+1)//2)
	print(ans%mod)
	for d in range(3, n):
	    temp1 = s[0:n-d]
	    ans+=(int(temp1)*45*(10**(2*(d-2))))


	    
	    temp2 = s[n-d:]
	    print(temp1, temp2)
	    print(ans%mod)
	    # print((int(temp1)*45*100))
	    ###print(temp1, temp2)

	    i=int(temp2[0])
	    given=int(temp2)
	    p=int(temp2[2:d])
	    upper=int(2*temp2[0]+((d-2)*'9'))
	    lower=int(2*temp2[0]+((d-2)*'0'))

	    if given<lower:
	        # print(10**(2*(d-2))*i*(i-1)/2)
	        ans+=10**(2*(d-2))*i*(i-1)//2
	        print('a')
	    elif given >= upper:
	        # print(100*(i)*(i+1)/2)
	        ans+=10**(2*(d-2))*(i)*(i+1)//2
	        print('b')
	    else:
	        # print(100*i*(i-1)/2+10*i*(p+1))
	        ans+=10**(2*(d-2))*i*(i-1)//2+(10**(d-2))*i*(p+1)
	        print('c')
	    print(ans%mod)

	d+=1
	temp2 = s[n-d:]

	i=int(temp2[0])
	given=int(temp2)
	p=int(temp2[2:d])
	upper=int(2*temp2[0]+((d-2)*'9'))
	lower=int(2*temp2[0]+((d-2)*'0'))

	if given<lower:
	    # print(10**(2*(d-2))*i*(i-1)/2)
	    ans+=10**(2*(d-2))*i*(i-1)//2
	elif given >= upper:
	    # print(100*(i)*(i+1)/2)
	    ans+=10**(2*(d-2))*(i)*(i+1)//2
	else:
	    # print(100*i*(i-1)/2+10*i*(p+1))
	    ans+=10**(2*(d-2))*i*(i-1)//2+10**(d-2)*i*(p+1)
	return int(final - ans)%mod
# x=[]
# y=[]
# for i in range(1, 10000000):
# 	x.append(i%mod)
# 	y.append(encoding_function(str(i))%mod)

# plt.plot(x, y)
# plt.show()

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

for t in range(int(input())):
	nl, l = input().split()
	nr, r = input().split()
	# r=random.randrange(10**18)
	ans1=encoding_function(str(r))
	ans2=encoding_function(str(int(l)-1))
	print((ans1-ans2)%mod)
	# summ=0
	# for i in range(int(l), int(r)+1):
	# 	summ+=getsum_modified(i)  
	# 	print(summ%mod, (ans1-ans2)%mod)
	#print((ans2-ans1)%mod)