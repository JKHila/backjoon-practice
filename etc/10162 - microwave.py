import sys
N = input()

p = [300,60,10]
res = [0,0,0]
while N > 0:
    for i in range(3):
        if p[i] <= N:
            res[i] += 1
            N -= p[i]
            break
        if N == 0:
            break
        if N < p[2]:
            print "-1"
            sys.exit()

st=""
st = str(res[0])+" "+str(res[1])+" "+str(res[2])
print st

