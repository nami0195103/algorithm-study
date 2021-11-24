//다익스트라(우선순위큐)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 2147483647

int main() {
	int n, m, a, b, i, j, dst, w;
	priority_queue<pair<int, int>> pq;
	vector<pair<int, int>> v[1001];
	pair<int, int> tmp;
	vector<int> dist;

	scanf("%d\n%d", &n, &m);
	dist.assign(n + 1, INF);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &j, &tmp.first, &tmp.second);
		v[j].push_back(tmp);
	}
	scanf("%d %d", &a, &b);

	//초기화
	dist[a] = 0;
	pq.push(make_pair(0, a));

	while (n--) {
		dst = pq.top().second;
 		w = pq.top().first * -1;
		pq.pop();

		//이미 더 짧은 경로를 알면 볼필요 x
		if (dist[dst] < w)
			continue;

		for (i = 0; i < v[dst].size(); i++) {
			//최단경로 갱신
			if (dist[v[dst][i].first] > w + v[dst][i].second) {
				dist[v[dst][i].first] = w + v[dst][i].second;
				pq.push(make_pair((w + v[dst][i].second) * -1, v[dst][i].first));
			}
		}
	}

	printf("%d\n", dist[b]);
}
