def f(n):
	ans = 0
	for i in range(n + 1):
		x = str(i)
		s = len(x)
		f = True

		for j in range(s):
			if j < (s - 1):
				if x[j] == x[j + 1]:
					f = False
			if j < (s - 2):
				if x[j] == x[j + 2]:
					f = False

		if f:
			ans += 1

	return ans

print(f(70000))