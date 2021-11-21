//prim - 배열로 짜면 대략 400MB라 메모리초과
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 2147483647

int main() {
	int v, e, i, idx, val, cnt;
	vector<int> tmp(3);
	vector<int> distance;
	vector<bool> visited;
	vector<vector<int>> w;
	long long ans = 0;

	scanf("%d %d", &v, &e);
	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
		w.push_back(tmp);
	}

	distance.assign(v + 1, INF);
	visited.assign(v + 1, false);
	for (i = 0; i < e; i++) {
		if (w[i][0] == 1)
			distance[w[i][1]] = w[i][2];
		else if (w[i][1] == 1)
			distance[w[i][0]] = w[i][2];
	}

	for (cnt = 1; cnt < v; cnt++) {
		val = INF;
		for (i = 2; i <= v; i++) {
			if (!visited[i] && distance[i] < val) {
				idx = i;
				val = distance[i];
			}
		}
		ans += val;
		visited[idx] = true;
		for (i = 0; i < e; i++) {
			if (w[i][0] == idx && w[i][2] < distance[w[i][1]])
				distance[w[i][1]] = w[i][2];
			if (w[i][1] == idx && w[i][2] < distance[w[i][0]])
				distance[w[i][0]] = w[i][2];
		}
	}

	printf("%lld\n", ans);
}
