st = raw_input()

n = []
for i in st:
    n.append(i)

n.sort(reverse=True)

res = ""
for i in n:
    res += str(i)

print res