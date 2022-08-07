import sys
input = sys.stdin.readline

INF = 2e9

v = int(input())
e = int(input())
dist = [[INF] * (v + 1) for _ in range(v + 1)]
for i in range(1, v + 1):
    dist[i][i] = 0
for _ in range(e):
    a, b, cost = map(int, input().split())
    dist[a][b] = min(dist[a][b], cost)

for k in range(1, v + 1):
    for i in range(1, v + 1):
        for j in range(1, v + 1):
            if dist[i][k] != INF and dist[k][j] != INF:
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(1, v + 1):
    for j in range(1, v + 1):
        if dist[i][j] == INF:
            print(0, end=' ')
        else:
            print(dist[i][j], end=' ')
    print()
