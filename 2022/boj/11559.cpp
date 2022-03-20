//bfs
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

char arr[12][6];
bool visit[12][6];

bool check(vector<pair<int, int>> &v, int y, int x) {
	vector<pair<int, int>> save;	//save coordinates for param v
	queue<pair<int, int>> q;	//for bfs
	int cnt = 0, i, curY, curX;
	int dir[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };

	q.push(make_pair(y, x));
	visit[y][x] = true;

	while (!q.empty()) {
		save.push_back(q.front());
		curY = q.front().first;
		curX = q.front().second;
		q.pop();
		cnt++;

		for (i = 0; i < 4; i++) {
			curY += dir[i][0];
			curX += dir[i][1];
			if ((curY >= 0 && curY < 12 && curX >= 0 && curX < 6) && !visit[curY][curX] && arr[y][x] == arr[curY][curX]) {
				q.push(make_pair(curY, curX));
				visit[curY][curX] = true;
			}
			curY -= dir[i][0];
			curX -= dir[i][1];
		}
	}

	if (cnt >= 4) {
		v = save;
		return true;
	}
	else
		return false;
}

int main() {
	bool isExist = true;
	int i, j, ans = 0, tmp, dot;
	vector<pair<int, int>> v;

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 6; j++) {
			scanf("%c", &arr[i][j]);
		}
		scanf("%c", &j); //'\n'
	}

	while (isExist) {
		isExist = false;
		memset(visit, 0, sizeof(visit));

		//그룹 탐색
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 6; j++) {
				if (arr[i][j] != '.') {
					if (!visit[i][j] && check(v, i, j)) {
						isExist = true;
						for (auto e : v) {
							arr[e.first][e.second] = '.';
						}
					}
				}
			}
		}

		if (isExist) {
			ans++;
			//터진 자리 처리
			for (i = 0; i < 6; i++) {
				dot = 11;
				while (dot) {
					while (dot && arr[dot][i] != '.')
						dot--;
					tmp = dot - 1;
					while (tmp >= 0 && arr[tmp][i] == '.')
						tmp--;

					if (tmp >= 0) {
						arr[dot][i] = arr[tmp][i];
						arr[tmp][i] = '.';
						dot--;
					}
					else //내릴 블럭이 없는 경우(모두 '.' : tmp == -1)
						break;
				}
			}
		}
	}

	printf("%d\n", ans);
}
