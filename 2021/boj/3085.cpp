//dfs
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0, n;
char candy[50][50];

void calc_v(int y) {	//세로
	int i, tmp;

	for (i = 0; i < n - 1; i++) {
		if (candy[i][y] == candy[i + 1][y]) {
			tmp = i;
			while (i < n - 1 && candy[i][y] == candy[i + 1][y])
				i++;
			answer = max(answer, i - tmp + 1);
		}
	}
}

void calc_h(int x) {	//가로
	int i, tmp;

	for (i = 0; i < n - 1; i++) {
		if (candy[x][i] == candy[x][i + 1]) {
			tmp = i;
			while (i < n - 1 && candy[x][i] == candy[x][i + 1])
				i++;
			answer = max(answer, i - tmp + 1);
		}
	}
}

void dfs(int x, int y) {
	if (answer == n || x == n)
		return;

	//아래
	if (x < n - 1) {
		swap(candy[x + 1][y], candy[x][y]);
		calc_v(y);
		calc_h(x);
		calc_h(x + 1);
		swap(candy[x + 1][y], candy[x][y]);
	}

	//오른쪽
	if (y < n - 1) {
		swap(candy[x][y + 1], candy[x][y]);
		calc_v(y);
		calc_h(x);
		calc_v(y + 1);
		swap(candy[x][y + 1], candy[x][y]);
	}

	if (y == n - 1)
		dfs(x + 1, 0);
	else
		dfs(x, y + 1);
}

int main() {
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> candy[i][j];
		}
	}

	dfs(0, 0);
	printf("%d\n", answer);
}
