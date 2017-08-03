ham = []
bev = []
for i in range(3) :
    ham.append(int(raw_input()))

for i in range(2) :
    bev.append(int(raw_input()))

print min(ham) + min(bev) - 50
