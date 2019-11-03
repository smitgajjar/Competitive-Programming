n,m=[int(x) for x in input().split()]
narr=[int(x) for x in input().split()]
marr=[int(x) for x in input().split()]

minnn=min(narr)
minn=narr.index(minnn)
for i in range(len(marr)):
    print(minn,i)

maxxx=max(marr)
maxx=marr.index(maxxx)
for i in range(len(narr)):
    if i is not minn:
        print(i,maxx)

               
            
    

    
