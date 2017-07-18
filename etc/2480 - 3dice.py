N = map(int,raw_input().split())

def compare(n,m):
    if n==m:
        return True
    else:
        return False

if compare(N[0],N[1]) and compare(N[1],N[2]) and compare(N[0],N[2]):
    print str(10000+N[0]*1000)
elif compare(N[0],N[1]):
    print str(1000+N[0]*100)
elif compare(N[1],N[2]):
    print str(1000+N[1]*100)
elif compare(N[0],N[2]):
    print str(1000+N[0]*100)
else:
    print str(100*max(N))