st = raw_input()

res = st[0]
for i in range(len(st)):
    if st[i] == '-':
        res += st[i+1]

print res  