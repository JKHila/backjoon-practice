n = int(raw_input())
star = ""
space = ""
for i in range(n):
    star = ""
    space = ""
    for j in range(n - (i+1)):
        space +=" "
    for j in range(2 * (i+1) - 1):
        star +="*"
    print space + star
for i in range(2,n+1):
    star = ""
    space = ""
    for j in range(i-1):
        space +=" "
    for j in range(2 * n - (2*i-1)):
        star +="*"
    print space + star
    