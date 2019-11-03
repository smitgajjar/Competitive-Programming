from math import *
t=int(input())
for _ in range(t):
	n=int(input())
	k=int(input())
	if k%n==0:
		print(0)
	else:
		k%=n
		temp=k
		l=[0 for i in range(n)]
		for i in range(0, n, 2):
			if temp>0:
				l[i]=1
				temp-=1
		if temp!=0:
			for i in range(n-1, 0, -1):
				if temp==0:
					break
				if l[i]==0:
					l[i]=1
					temp-=1

		f_l=abs(l[n-1]-l[0])
		l_sl=abs(l[n-1]-l[n-2])
		add=max(f_l, l_sl)
		sum=0
		for i in range(n-2):
			sum+=abs(l[i]- l[i+1])
		sum+=add
		print(sum)
