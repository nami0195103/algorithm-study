//bfs - 매번 모든 맵에 대해 하는 것이 아니라 이전에 탐색하지 않았던 영역에 대해서만 bfs 수행하도록
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX_SIZE 1500

int day, r, c;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
char map[MAX_SIZE][MAX_SIZE];
bool isVisited[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> curSwan, nextSwan, curWater, nextWater;

int main() {
	int i, j, nr, nc;
	pair<int, int> p;
	bool find = false;
	
	scanf("%d %d\n", &r, &c);
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] != 'X') {
				curWater.push(make_pair(i, j));
			}
			if (map[i][j] == 'L' && curSwan.empty()) {
				curSwan.push(make_pair(i, j));
				isVisited[i][j] = true;
			}
		}
		scanf("%c", &j);
	}

	while (!find) {
		//백조
		while (!curSwan.empty()) {
			p = curSwan.front();
			curSwan.pop();
			for (i = 0; i < 4; i++) {
				nr = p.first + dir[i][0];
				nc = p.second + dir[i][1];
				if (nr >= 0 && nr < r && nc >= 0 && nc < c && !isVisited[nr][nc]) {
					isVisited[nr][nc] = true;
					if (map[nr][nc] == '.')
						curSwan.push(make_pair(nr, nc));
					else if (map[nr][nc] == 'X')
						nextSwan.push(make_pair(nr, nc));
					else
						find = true;
				}
			}
		}
		curSwan = nextSwan;
		while (!nextSwan.empty()) {
			nextSwan.pop();
		}

		//물
		if (!find) {
			while(!curWater.empty()) {
				p = curWater.front();
				curWater.pop();
				for (i = 0; i < 4; i++) {
					nr = p.first + dir[i][0];
					nc = p.second + dir[i][1];
					if (nr >= 0 && nr < r && nc >= 0 && nc < c && map[nr][nc] == 'X') {
						map[nr][nc] = '.';
						nextWater.push(make_pair(nr, nc));
					}
				}
			}
			curWater = nextWater;
			while (!nextWater.empty()) {
				nextWater.pop();
			}

			day++;
		}
	}

	printf("%d\n", day);
}
