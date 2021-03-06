//위상정렬
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m, i, j;
	vector<vector<int>> edge;	//연결 정보
	vector<int> ans;
	vector<int> in_deg;	//진입차수
	queue<int> q;

	//초기화
	scanf("%d %d", &n, &m);
	edge.assign(n + 1, vector<int>(0));
	in_deg.assign(n + 1, 0);
	for (i = 0; i < m; i++) {
		int k;
		scanf("%d %d", &j, &k);
		edge[j].push_back(k);
		in_deg[k]++;
	}

	//진입차수 0인 정점 queue에 추가
	for (i = 1; i <= n; i++) {
		if (!in_deg[i])
			q.push(i);
	}

	//위상정렬
	//queue가 비었는데 방문하지 않은 정점이 있다면 사이클 존재(for문으로 n번만 반복문 수행)
	while (!q.empty()) {
		i = q.front();
		q.pop();
		ans.push_back(i);
		for (auto iter : edge[i]) {
			if (--in_deg[iter] == 0)
				q.push(iter);
		}
	}

	for (auto iter : ans)
		printf("%d ", iter);
	printf("\n");

	return 0;
}
