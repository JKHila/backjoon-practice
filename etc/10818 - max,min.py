
N = input()

M =[]
M = map(int,raw_input().split())
 
M.sort()

print str(M[0]) + " " + str(M[N-1])