# Below is Python code for input/output 

import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r') 

# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

t=int(input())
for _ in range(1, t+1):
    n=int(input())
    inp=str(input())
    out=[]
    for i in range(len(inp)):
        if inp[i]=='S':
            out.append('E')
        else:
            out.append('S')
    print("Case #{}: ".format(_), end='')
    for i in range(len(out)):
        print(out[i], end='')
    print()
