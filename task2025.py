t = int(input())


def f(n, k):
    inOneTeam = n // k
    noOneTeam = n % k
    count = 0
    for i in range(noOneTeam):
        n -= inOneTeam + 1
        count += n * (inOneTeam + 1)
    for i in range(k - noOneTeam):
        n -= inOneTeam
        count += n * inOneTeam
    return count


for i in range(t):
    n, k = map(int, input().split())
    print(f(n, k))
