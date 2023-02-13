n = int(input())
w = [int(x) for x in input().split()]
diff = float('inf')
limit = 2 << (n - 1)

for i in range(limit):
    sum1 = 0
    sum2 = 0
    k = i
    for j in range(n):
        if k & 0x1 == 0:
            sum1 += w[j]
        else:
            sum2 += w[j]
        k = k >> 1
    diff = min(diff, abs(sum1 - sum2))

print(diff)



