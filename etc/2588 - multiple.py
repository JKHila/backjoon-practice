n1 = int(raw_input())
n2 = int(raw_input())

mul = n1 * n2
print n1 * (n2 % 10)
n2 /= 10
print n1 * (n2 % 10)
n2 /= 10
print n1 * (n2 % 10)
print mul