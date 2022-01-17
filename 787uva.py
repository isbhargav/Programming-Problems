
while True:
    try:
        numbers = input()
        numbers = [ int(x) for x in numbers.split()]
        n = len(numbers)-1
        ans = -999999 
        for i in range(n):
            prev = numbers[i]
            ans = max(ans,prev)
            for j in range(i+1,n):
                prev = prev*numbers[j]
                ans = max(ans,prev)
        print(ans)
    except EOFError:
        break

