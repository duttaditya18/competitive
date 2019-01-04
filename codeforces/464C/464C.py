s = input()
n = int(input())
d = []
t = []

for i in range(n):
    a = input()
    a = a.split('->')

    s = s.replace(a[0], a[1])

if s:
    print(int(s) % 1000000007)
else:
    print(0)
