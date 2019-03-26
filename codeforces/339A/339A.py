s = str(input())
s = s.split('+')

s = sorted(int(i) for i in s)

print(*s, sep='+')
