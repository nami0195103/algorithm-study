import heapq
import sys

input = sys.stdin.readline
INF = int(2e9)

v, e, x = map(int, input().split())
graph = [[] for _ in range(v + 1)]  #[(dst, cost), ...]
for _ in range(e):
    a, b, t = map(int, input().split())
    graph[a].append((b, t))

def dijkstra(start):
    q = []  #(cost, vertex)
    dist = [INF] * (v + 1)
    dist[start] = 0
    heapq.heappush(q, (0, start))
    
    while q:
        cur_cost, cur = heapq.heappop(q)
        if cur_cost > dist[cur]:    #heapq에 push한 이후로 해당 vertex까지의 cost가 갱신된 경우
            continue
        for edge_dst, edge_cost in graph[cur]:
            if dist[edge_dst] > dist[cur] + edge_cost:
                dist[edge_dst] = dist[cur] + edge_cost
                heapq.heappush(q, (dist[edge_dst], edge_dst))

    return dist

ans = 0
back = dijkstra(x)
for i in range(1, v + 1):
    if i == x:
        continue
    go = dijkstra(i)
    if ans < go[x] + back[i]:
        ans = go[x] + back[i]
print(ans)
