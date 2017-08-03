while True:
    M = map(int,raw_input().split())

    if M[0] == 0 and M[1] == 0:
        break
    elif M[0] > M[1]:
        print "Yes"
    else:
        print "No"