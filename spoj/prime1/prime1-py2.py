# time limit exceeded

def checkprime(num):
    if num == 1:
        return 0
    for f in range(2, int(num / 2) + 1):
        if num % f == 0:
            return 0
        else:
            continue
        return 1

def genprime(n1, n2):
    for i in range(n1, n2 + 1):
        checkc = checkprime(i)
        if checkc == 0:
            continue
        else:
            print(i)
    print("\n")

test = int(input())
i = 0
while i < test:
    num = raw_input()
    n1, n2 = num.split(" ")
    i += 1
    n1 = int(n1)
    n2 = int(n2)
    genprime(n1, n2)
