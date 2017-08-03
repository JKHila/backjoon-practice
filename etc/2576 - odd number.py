MIN = 999
SUM = 0
for i in range(7):
    n = input()
    if n%2 == 1:
        SUM += n
        if  n < MIN:
            MIN = n

if SUM == 0:
    print -1
else:
    print SUM
    print MIN