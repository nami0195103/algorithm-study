//BFS
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define check(a, b) (a >= 0 && a < n && b >= 0 && b < m)

int n, m, k;
int ans = 0;
bool trash[100][100];
bool visited[100][100];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

int calc(int cnt) {
	int i, j, r, c, nextr, nextc;

	if (q.empty()) {
		return cnt;
	}

	r = q.front().first;
	c = q.front().second;
	q.pop();

	for (i = 0; i < 4; i++) {
		nextr = r + dy[i];
		nextc = c + dx[i];
		if (check(nextr, nextc) && trash[nextr][nextc] && !visited[nextr][nextc]) {
			visited[nextr][nextc] = true;
			q.push(make_pair(nextr, nextc));
			cnt++;
		}
	}

	return calc(cnt);
}

int main() {
	int i, j, r, c, tmp;

	cin >> n >> m >> k;
	for (i = 0; i < k; i++) {
		cin >> r >> c;
		trash[r - 1][c - 1] = true;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (trash[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
				tmp = calc(1);
				ans = ans > tmp ? ans : tmp;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
