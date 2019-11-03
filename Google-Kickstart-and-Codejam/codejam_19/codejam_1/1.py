def solve():
   n=int(input())
   temp=[]
   for i in range(n):
      strin=str(input())
      temp[i]=strin[::-1]
   
   ss=set()
   strr=''
   cnt=0
   tot=0
   while tot<len(temp):
      for i in range(len(temp[tot]))
         strr=''
         for j in range(i, len)):
            if s[i]==s[j]:
               strr+=s[i]
            else:
               if strr not in ss:
                  cnt+=1
               ss.add(strr)
               break
      tot-=1
   return cnt

t=int(input())
for _ in range(t):
   cnt=solve()
   print("Case #{}: {}".format(_+1, cnt), end='')
