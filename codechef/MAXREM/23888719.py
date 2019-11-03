n=int(input())
arr=[int(a) for a in input().split()]
max_a=0
for i in arr:
    if i > max_a:
        max_a=i
max2_a=0
for i in arr:
    if i > max2_a and i!=max_a:
        max2_a=i
print(max2_a)