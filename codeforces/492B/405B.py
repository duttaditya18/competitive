n, l = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort()

diff = []
diff.append(a[0])
for i in range(n - 1):
    diff.append((a[i + 1] - a[i])/2)
diff.append(l - a[n - 1])

print(max(diff))
