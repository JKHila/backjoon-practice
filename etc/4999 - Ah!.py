N = raw_input()
M = raw_input()

n=0
m=0
for i in N:
    if i != 'h':
        n += 1
    else:
        break
for i in M:
    if i != 'h':
        m += 1
    else:
        break
if n >= m:
    print "go"
else:
    print "no"

