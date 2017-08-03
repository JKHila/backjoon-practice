N = raw_input()

res = 0
pre = 0 # 0 = '(', 1 = ')'
if N[0] == '(':
    pre = 1
else:
    pre = 0
cur = 0
for i in range(len(N)):
    if N[i] == '(':
        cur = 0
    else:
        cur = 1
    if pre == cur:
        res += 5
    else:
        res += 10
    pre = cur
print res