def sln():
    n=int(input())
    if n==1:
        print(1)
        return 
    ns=n//2+1
    for i in range(ns-1):
        x="1"+"0"*i+"3"+"0"*(ns-2-i)
        print(int(x)**2)
    for i in range(ns-1):
        x="3"+"0"*i+"1"+"0"*(ns-2-i)
        print(int(x)**2)
    x="14"+"0"*(ns-2)
    print(int(x)**2)
    
tc= int(input())
for t in range(tc):
    sln()    
        