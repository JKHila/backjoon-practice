def timetoint(t):
    temp = t.split(':')
    return int(temp[0]) * 60 + int(temp[1])

def inttotime(t):
    h = t // 60
    m = t % 60

    HH = "0" + str(h) if h < 10 else str(h)
    MM = "0" + str(m) if m < 10 else str(m)

    return HH + ":" + MM

def solution(n, t, m, timetable):
    answer = ''
    temp = 0

    for i in range(len(timetable)):
        timetable[i] = timetoint(timetable[i])
        
    timetable.sort()
    cur = 540

    for i in range(n):
        for j in range(m):
            if len(timetable) > 0 and timetable[0] <= cur:
                temp = timetable[0] - 1
                timetable.pop(0)
            else:
                temp = cur
                        
        cur += t
        
    answer = inttotime(temp)

    return answer