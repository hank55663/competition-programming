while True:
    try:
        s = input()
        num = s.split('*')
        ans = 1
        for x in num:
            xx = x.split('+')
            ans *= int(xx[0])
            for y in xx[1:]:
                ans += int(y)
        print(ans)
    except:
        break