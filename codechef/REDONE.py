'''
def modi(n, m) : 
    n = n % m;
    for i in range(1, m) :
        if ((n * i) % m == 1) :
            return x
    return 1
def fact(n):    
    hellprime=1000000007
    ans = hellprime -1
    for i in range (n + 1, hellprime): 
        ans = (ans * modi(i, hellprime)) % hellprime 
    return ans
'''
hellprime=1000000007
arr=[1]
a=1
b=2
for i in range(999999):
    b=(a + b%hellprime + (a*b)%hellprime)%hellprime
    arr.append(b)
    if(i==0):
        a+=2
    else:
        a+=1
t=int(input())
for _ in range(t):
    n=int(input())
    print(arr[n-1])
