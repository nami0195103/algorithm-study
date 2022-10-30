//BFS
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 987654321

int n, k;
queue<pair<int, int>> q;
int sec = MAX, cnt = 0;
int visited[100001];
int dx[3] = { 1, -1, 0 };

int main() {
	int i;
	pair<int, int> cur, next;

	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n" << 1 << "\n";
		return 0;
	}

	memset(visited, -1, sizeof(visited));
	cur.first = n;
	cur.second = 0;
	visited[n] = 0;
	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		next.second = cur.second + 1;
		if (next.second > sec)
			break;
		dx[2] = cur.first;

		for (i = 0; i < 3; i++) {
			next.first = cur.first + dx[i];
			if (next.first >= 0 && next.first <= 100000 && (visited[next.first] == -1 || cur.second == visited[next.first])) {
				if (next.first == k) {
					sec = next.second;
					cnt++;
				}
				else {
					visited[next.first] = cur.second;
					q.push(next);
				}
			}
		}
	}

	cout << sec << "\n" << cnt << "\n";
}
