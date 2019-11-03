for _ in range(int(input())):
	arr=[1 for i in range(100)]
	m, x, y=[int(i) for i in input().split()]
	cops=[int(i) for i in input().split()]
	pro=x*y
	for i in range(m):
		val=cops[i]
		for k in range(max(0, val - pro - 1), min(99, val + pro - 1)+1):
			arr[k]=0
	cnt=0
	for i in arr:
		cnt+=i
	print(cnt)