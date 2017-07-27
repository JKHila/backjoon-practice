T = int(raw_input())

o = 1
while T > 0:
    n,m =(raw_input().split())
    n,m = [int(n),int(m)]
    print "Case #"+str(o)+": " +str(n+m)
    o+=1
    T -= 1