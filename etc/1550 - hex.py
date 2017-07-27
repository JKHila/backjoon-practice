six = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'A':10,'B':11,'C':12,'D':13,'E':14,'F':15}

M = raw_input()
length = len(M)
res = 0
for i in M:
    res += six[i] * pow(16,length-1)
    length -= 1
print res