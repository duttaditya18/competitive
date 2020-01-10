t=int(input())
for i in range(t):
    n,b=map(int,input().split())
    print(max(1,n-b))
