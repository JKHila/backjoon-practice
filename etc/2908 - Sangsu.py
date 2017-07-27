n,m = raw_input().split()

n,m = [int(n),int(m)]

n2 = ""
m2 = ""
for i in range(3):
    n2 += str(n % 10)
    n/=10
    m2 += str(m % 10)
    m/=10
    
if int(n2) > int(m2):
    print n2
else:
    print m2