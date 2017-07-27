n = input()

star =""
space =""
for i in range(n):
    star = ""
    space =""
    for j in range(n-(i+1)):
        space += " "
    for k in range(i+1):
        star += "*"
    print space+star
for i in range(n-1):
    star = ""
    space =""
    for j in range(i+1):
        space += " "
    for k in range(n-(i+1)):
        star += "*" 
    print space+star       