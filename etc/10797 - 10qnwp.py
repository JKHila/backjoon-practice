day = int(raw_input())
l = map(int,raw_input().split())
cnt = 0
for i in l:
    if day == i:
        cnt += 1

print cnt