n = ["c=","c-","dz=","d-","lj","nj","s=","z="]
st = input()

res = 0

for key in n:
    if st.find(key) != -1:
        print(key)
        st = st.replace(key,"")
        res += 1
res += len(st)
print(res)