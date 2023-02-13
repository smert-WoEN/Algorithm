n = int(input())

maxPower = 0
power = 0

for i in range(n):
    power += int(input())
    maxPower = max(maxPower, power)
    power = max(power, 0)

print(maxPower)
