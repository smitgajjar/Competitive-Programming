x=7
y=12
l=4
r=17
for z in range(l, r+1):
	print(bin(x), bin(z))
	print(bin(y), bin(z))
	print((x&z)*(y&z))