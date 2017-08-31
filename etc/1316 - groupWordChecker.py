t = int(input())
a = []
for i in range(26):
    a.append(0)

resCnt = 0
while t > 0:
    res = True
    for i in range(26):
        a[i] = 0
        
    st = input()
    cur = ""
    for i in st:
        a[ord(i)-97] += 1
        if a[ord(i)-97] > 1 and cur != i:
            res = False
        cur = i
    
    if res:
        resCnt += 1
    t -= 1
print (resCnt)