a,b = raw_input().split()
minA,minB,maxA,maxB = ["","","",""]

for i in a:
    if i == "5":
        maxA += "6"
        minA += "5"
    elif i == "6":
        minA += "5"
        maxA += "6"
    else:
        minA += i
        maxA += i
        
for i in b:
    if i == "5":
        maxB += "6"
        minB += "5"
    elif i == "6":
        minB += "5"    
        maxB += "6"    
    else:
        minB += i
        maxB += i

resMin = int(minA) + int(minB)
resMax = int(maxA) + int(maxB)

print str(resMin)+" "+str(resMax)