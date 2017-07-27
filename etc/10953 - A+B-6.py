T = int(raw_input())

while T > 0:
    n,m =(raw_input().split(","))
    n,m = [int(n),int(m)]
    print n+m
    T -= 1