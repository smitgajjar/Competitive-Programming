for _ in range(int(input())):
	n=int(input())
	s=input()
	cnt=0
	for i in s:
		cnt+=(ord(i)-ord('0'))
	print(cnt*(cnt+1)//2)