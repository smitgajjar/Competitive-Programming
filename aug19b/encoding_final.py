# import random
mod=1000000007
modinv2=500000004
# import matplotlib.pyplot as plt
val=[]
def modf(s):
	ans=0
	for i in range(len(s)):
                val.append(ans)
                ans=(ans*10+int(s[i]))%mod
		
	return ans

# def modinv(q, m=mod):
#     mi = m 
#     y = 0
#     x = 1

#     while (q > 1) : 
#         quo = q // m 
#         t = m  
#         m = q % m 
#         q = t 
#         t = y 
#         y = x - quo * y 
#         x = t 
#     if (x < 0) : 
#         x = x + mi
#     return x

def power(a, b, p=mod) : 
	r = 1
	a = a % p 

	while (b > 0) :
		if ((b & 1) == 1) : 
			r = (r * a)% p 
		b = b >> 1
		a = (a * a) % p
	return r

def moreOrEqToUpper(given, upper, d):
	if given == upper:
		return True
	for i in range(d):
		if int(given[i])>int(upper[i]):
			return True
	return False

def lessThanLower(given, lower, d):
	for i in range(d):
		if int(given[i])<int(lower[i]):
			return True
	return False

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
	n=len(s)

	if n<4:
		sum1=0
		for i in range(1,int(s)+1):
		    sum1+=(getsum_modified(i))
		return sum1%mod
	
	final=(((modf(s)*modf(s))%mod + modf(s))%mod * modinv2)%mod
	ans=0

	temp1 = s[0:n-2]
	temp2 = s[n-2:]
	# print((int(temp1)*45))
	ans+=(modf(temp1)*45)%mod
	ans=ans%mod
	# print(ans)
	t1=int(temp2[0])
	t2=int(temp2[1])
	if t2<t1:
	    # print((t1-1)*t1/2)
	    ans+=((t1-1)*t1//2)%mod
	else:
	    # print((t1*(t1+1)/2))
	    ans+=(t1*(t1+1)//2)%mod
	# print(ans)
	pwr=1
	pwr2=1

	tt1=int(s[-2])
	lt=int(s[-3])
	for d in range(3, n+1):
		pwr=(pwr*100)%mod
		pwr2=(pwr2*10)%mod
		if d != n:
		    #temp1 = s[0:n-d]
		    ans+=(((val[-d-1]*45)%mod) * (pwr))%mod
		    ans=ans%mod
		temp2 = s[n-d:]
		# print(temp1, temp2)
		# print(ans)
	    
	    # print((int(temp1)*45*100))
	    ###print(temp1, temp2)
		i=int(temp2[0])
		#given=temp2
		#p=(val[-1]-val[-d])%mod
		p=(temp2[2:d])
		#upper=2*temp2[0]+((d-2)*'9')
		#lower=2*temp2[0]+((d-2)*'0')

		#k=power(10, 2*d-4)
		#pk=power(10, d-2)
		if temp2[1]<temp2[0]:
	        # print(10**(2*(d-2))*i*(i-1)/2)
		   	ans+=((pwr*i*(i-1))%mod * modinv2)%mod
		   	ans=ans%mod
		   	# ans+=10**(2*(d-2))*i*(i-1)//2
		   	# print('a')
		elif temp2[1]>temp2[0]:
	        # print(100*(i)*(i+1)/2)
		    ans+=(((pwr*i*(i+1))%mod) * modinv2)%mod
		    ans=ans%mod
		    # ans+=10**(2*(d-2))*(i)*(i+1)//2
		    # print('b')
		else:
	        # print(100*i*(i-1)/2+10*i*(p+1))
		    ans+=((((pwr*i*(i-1))%mod) * modinv2)%mod + (pwr2*i*p)%mod + (pwr2*i)%mod ) % mod
		    ans=ans%mod
		    # ans+=10**(2*(d-2))*i*(i-1)//2+(10**(d-2))*i*(p+1)
		    # print('c')
		# print(ans)
	return (final - ans)%mod
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
