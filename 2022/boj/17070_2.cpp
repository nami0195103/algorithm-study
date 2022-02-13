//DFS(완전탐색?) _1 코드정리
#include <iostream>
using namespace std;

typedef struct {
	int y, x;
} _dir;

_dir dir[3] = { {0, 1}, {1, 0}, {1, 1} };	//가로 세로 대각선

int n, arr[16][16];
int answer;

void func(int y, int x, int shape) {
	if (y == n - 1 && x == n - 1) {
		answer++;
		return;
	}

	int i, nextY, nextX;
	for (i = 0; i < 3; i++) {
		if (i + shape == 1)	//세로->가로, 가로->세로 skip
			continue;

		nextY = y + dir[i].y;
		nextX = x + dir[i].x;
		if (nextY >= n || nextX >= n || arr[nextY][nextX])
			continue;
		if (i == 2 && (arr[nextY][x] || arr[y][nextX]))	//대각선이면 가로세로칸도 확인해야 함
			continue;
		
		func(y + dir[i].y, x + dir[i].x, i);
	}
}

int main() {
	int i, j;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	func(0, 1, 0);
	printf("%d\n", answer);

	return 0;
}
