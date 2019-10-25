f = open("in.in","a+")

for i in range(1000000):
    print(0, end = '', file = f)

f.close()
