n = int(input())

for i in range(0, n):
    l, r = map(int, input().split())
    print(l, r - r%l)