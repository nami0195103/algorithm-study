//벨만포드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654231

int main() {
	int n, m, a, b, i, j;
	vector<pair<pair<int, int>, int>> edges;
	vector<int> dist;

	scanf("%d %d", &n, &m);
	dist.assign(n + 1, INF);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &j);
		edges.push_back(make_pair(make_pair(a, b), j));
	}
	scanf("%d %d", &a, &b);

	dist[a] = 0;
	while (n--) {	//출발점 제외한 모든 도시(vertex)에 대해
		for (i = 0; i < m; i++) {	//모든 버스(edge)에 대해
			j = edges[i].first.second;
			dist[j] = min(dist[j], dist[edges[i].first.first] + edges[i].second);
		}
	}

	printf("%d\n", dist[b]);
}
