
while True:
    try:
        s = input()
        num = s.split()
        ans = 0
        for x in num:
            ans += int(x)
        print(ans)
    except:
        break