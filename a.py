n = ["c=","c-","dz=","d-","lj","nj","s=","z="]
st = input()

res = 0
cnt = 0
while cnt < 8:
    for key in n:
        idx = st.find(key)
        if idx != -1:
            st = st.replace(key,"",1)
            res += 1
            cnt = 0
            break
        cnt += 1
res += len(st)
print(res)