st = input()
st = st.lower()
a = []
for i in range(26):
    a.append(0)
for i in st:
    a[ord(i) - 97] += 1
mx = 0
res = ""
same = False
for i in range(len(a)):
    if a[i] != 0:
        if mx < a[i]:
            mx = a[i]
            res = i
            same = False
        elif mx == a[i]:
            res = "?"
            same = True
if not same:
    print(chr(res+65))
else:
    print (res)


