MAX = 0
maxNum = 0
for i in range(9):
    n = input()
    if(n > MAX):
        MAX = n
        maxNum = i+1
print MAX
print maxNum