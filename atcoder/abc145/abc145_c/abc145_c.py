from itertools import permutations
import math

n = int(input())

x = []
y = []
v = []

for i in range(n):
    v.append(i)
    x1, y1 = map(int, input().split())
    x.append(x1)
    y.append(y1)

ans = 0
cnt = 0

for i in list(permutations(v)):
    for f in range(1, n):
        ans += math.sqrt((x[i[f - 1]] - x[i[f]])*(x[i[f - 1]] - x[i[f]]) + (y[i[f - 1]] - y[i[f]])*(y[i[f - 1]] - y[i[f]]))
    cnt += 1

ans /= cnt
print(ans)
