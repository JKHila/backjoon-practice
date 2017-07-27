#-*- coding: utf-8 -*-
total = 0
l = map(int,raw_input().split())
for i in range(5):
    total += l[i]*l[i]

print total % 10