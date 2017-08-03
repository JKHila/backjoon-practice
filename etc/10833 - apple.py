N = input()
res = 0
for i in range(N):
    s,a = raw_input().split()
    s,a = [int(s),int(a)]
    res += a % s
print res
