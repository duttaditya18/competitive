from sys import stdin
n = 260
dp = [None] * (n + 1)

dp[0] = 1
dp[1] = 1

for i in range(2, n + 1):
	dp[i] = dp[i - 1] + 2*dp[i - 2]


for line in stdin:
	x = int(line)
	print(dp[x])
