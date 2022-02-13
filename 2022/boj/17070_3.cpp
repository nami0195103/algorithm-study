//DP
#include <iostream>
using namespace std;

typedef struct {
	int y, x;
} _dir;

_dir dir[3] = { {0, 1}, {1, 0}, {1, 1} };	//가로 세로 대각선

int n, arr[17][17];
int answer[17][17][3];

void dp(int y, int x) {	//answer[y][x][] 계산(answer[prevY][prevX][] 합)
	if (!arr[y][x]) {
		int i, prevY, prevX;

		for (i = 0; i < 3; i++) {
			prevY = y - dir[i].y;
			prevX = x - dir[i].x;

			if (i == 2 && (arr[y - 1][x] || arr[y][x - 1]))
				break;

			answer[y][x][i] += answer[prevY][prevX][0] + answer[prevY][prevX][1] + answer[prevY][prevX][2];
			if (i != 2)
				answer[y][x][i] -= answer[prevY][prevX][1 - i];
		}
	}

	if (y == n && x == n)
		return;
	else if (x == n)
		dp(y + 1, 1);
	else
		dp(y, x + 1);
}

int main() {
	int i, j;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	answer[1][2][0] = 1;
	dp(1, 3);
	printf("%d\n", answer[n][n][0] + answer[n][n][1] + answer[n][n][2]);

	return 0;
}
