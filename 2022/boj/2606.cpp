//BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> connected[101];
bool visited[101];
queue<int> q;

int main() {
	int i, j, k, n, cnt, src, ans;

	cin >> n >> cnt;
	for (i = 0; i < cnt; i++) {
		cin >> j >> k;
		connected[j].push_back(k);
		connected[k].push_back(j);
	}

	visited[1] = true;
	q.push(1);
	ans = 0;

	while (!q.empty()) {
		src = q.front();
		q.pop();

		for (auto iter : connected[src]) {
			if (!visited[iter]) {
				visited[iter] = true;
				q.push(iter);
				ans++;
			}
		}
	}

	cout << ans << '\n';
}
