//bfs + 완전탐색
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <functional>
using namespace std;

int r, c, n;
char arr[101][101];

//내릴 수 있는 줄 수 return
int available(const vector<pair<int, int>>& v) {
	int cnt = 0;
	bool flag = true;
	bool cluster[101][101] = { 0, };

	for (auto e : v)
		cluster[e.first][e.second] = true;

	while (flag) {
		for (auto e : v) {
			if (e.first + cnt + 1 == r) {
				flag = false;
				break;
			}
			else if (!cluster[e.first + cnt + 1][e.second] && arr[e.first + cnt + 1][e.second] == 'x') {
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}

	return cnt;
}

//영향받는 클러스터가 있다면 내릴 수 있는 줄 수 return
int find(int y, int x, vector<pair<int, int>> &v) {
	vector<pair<int, int>> save;
	queue<pair<int, int>> q;
	int curY, curX, i, j;
	bool visit[101][101] = { 0, };
	int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };	//위, 왼, 오, 아래

	for (i = 0; i < 4; i++) {
		save.clear();
		if ((y + dir[i][0] >= 0 && y + dir[i][0] < r && x + dir[i][1] >= 0 && x + dir[i][1] < c) && arr[y + dir[i][0]][x + dir[i][1]] == 'x' && !visit[y + dir[i][0]][x + dir[i][1]]) {
			//클러스터 bfs
			q.push(make_pair(y + dir[i][0], x + dir[i][1]));
			visit[y + dir[i][0]][x + dir[i][1]] = true;
			while (!q.empty()) {
				save.push_back(q.front());
				curY = q.front().first;
				curX = q.front().second;
				q.pop();
				visit[curY][curX] = true;

				for (j = 0; j < 4; j++) {
					curY += dir[j][0];
					curX += dir[j][1];
					if ((curY >= 0 && curY < r && curX >= 0 && curX < c) && arr[curY][curX] == 'x' && !visit[curY][curX]) {
						q.push(make_pair(curY, curX));
						visit[curY][curX] = true;
					}
					curY -= dir[j][0];
					curX -= dir[j][1];
				}
			}
			
			sort(save.begin(), save.end());
			j = available(save);
			if (j) {
				v = save;
				return j;
			}
		}
	}

	return 0;
}

int main() {
	int i, j, k, h;
	vector<pair<int, int>> v;

	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++)
		scanf("%s", arr[i]);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &h);
		h = r - h;

		//미네랄 위치 확인
		if (i % 2) {
			for (j = 0; j < c; j++) {
				if (arr[h][j] == 'x')
					break;
			}
		}
		else {
			for (j = c - 1; j >= 0; j--) {
				if (arr[h][j] == 'x')
					break;
			}
		}
		if (j == -1 || j == c)
			continue;
		else
			arr[h][j] = '.';

		//내릴 수 있는 클러스터가 있는지 확인
		k = find(h, j, v);
		if (k) {
			vector<pair<int, int>>::reverse_iterator riter;	//밑에줄(row가 큰 쪽)부터 내리기 위해 reverse iterator 사용
			for (riter = v.rbegin(); riter != v.rend(); riter++) {
				arr[riter->first + k][riter->second] = 'x';
				arr[riter->first][riter->second] = '.';
			}
		}
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
