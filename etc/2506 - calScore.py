N = input()
M = map(int,raw_input().split())

cur = 0
res = 0
for i in M:
    if i == 1:
        cur += 1
        res += cur
    else:
        cur = 0
    
print res
