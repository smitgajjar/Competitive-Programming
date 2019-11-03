t=int(input())
for _ in range(t):
	n=int(input())
	arr=[int(i) for i in input().split()]
	sum=0
	for i in arr:
		sum+=i
	avg=sum/n
	note=[]
	idx=[]
	flag=False

	for i in range(len(arr)):
		if ((sum-arr[i])/(n-1)) == avg:
			# ans=arr[i]
			note.append(arr[i])
			idx.append(i+1)
			flag=True
			break
	if flag is True:
		minn=1000000001
		for i in range(len(note)):
			if note[i]<minn:
				ans=idx[i]
				minn=note[i]
		print(ans)
	else:
		print("Impossible")