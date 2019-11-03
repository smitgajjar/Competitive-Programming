from math import *
t=int(input())
for _ in range(t):
    print("Q 0 0", flush=True)
    d00=int(input())
    print("Q 0 1000000000", flush=True)
    d01=int(input())
    print("Q 1000000000 1000000000", flush=True)
    d11=int(input())
    c=ceil((d00-d01+1000000000)/2.0)
    print("Q 0 ", c, flush=True)
    xl=int(input())
    yl=d00-xl
    yu=xl-d01+1000000000
    xu=2000000000-d11-yu
    print("A #{} #{} #{} #{}".format(xl, yl, xu, yu), flush=True)
    cor=bool(input())
