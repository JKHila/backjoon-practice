import sys
N = input()

res = 0
while True:
    if N % 5 == 0:
        res += N/5
        break
    if N >= 3:
        N -= 3
        res +=1
    else:
        res = -1
        break
print res
