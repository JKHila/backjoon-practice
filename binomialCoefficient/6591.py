import sys
sys.setrecursionlimit(1000000)

def combination(n,m):
    if n==m: return 1
    else:
        return n * combination(n-1,m) / (n-m)
n = 1
m = 1
numbers = []
while True:
    n,m = raw_input().split()
    n,m = [int(n),int(m)] 
    if n == 0 and m ==0:
        break
    numbers.append([n,m])

for key in numbers :
    print combination(key[0],key[1])

