import os 
from collections import deque, defaultdict

def isbipartite(col, g):
    col[1] = 0
    q = deque()
    q.append(1)
    bipartite = True
    while q:
        v = q.popleft()
        for i in range(0, len(g[v])):
            if col[g[v][i]] == -1:
                col[g[v][i]] = col[v] ^ 1
                q.append(g[v][i])
            else:
                bipartite = bipartite & (col[g[v][i]] != col[v])

    return bipartite

def main():
    N = 200100
    g = defaultdict(list)
    col = [-1]*N
    src = []
    dest = []
    n, m = map(int, input().split(" "))

    for i in range(0, m):
        s, d = map(int, input().split(" "))
        g[s].append(d)
        g[d].append(s)
        src.append(s)
        dest.append(d)
    
    edges = list(zip(src, dest))

    if not isbipartite(col, g):
        print("NO")
        exit(0)

    ans = ""

    for i in range(0, m):
        if col[edges[i][0]] == 0:
            ans = ans + "1"
        else:
            ans = ans + "0"

    print("YES")
    print(ans)

if __name__ == "__main__":
    main()