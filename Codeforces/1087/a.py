s = input()

n = len(s)

i = (n-1)//2 
j = i+1

ans = ""

while i>=0 or j<n:
    if i>=0:
        ans += s[i]
    if j<n:
        ans += s[j]
    i = i-1
    j = j+1

print(ans)