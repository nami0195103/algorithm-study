//iteration
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0, n;
char candy[50][50];

void col(int c) {	//세로
	int i, tmp;

	for (i = 0; i < n - 1; i++) {
		if (candy[i][c] == candy[i + 1][c]) {
			tmp = i;
			while (i < n - 1 && candy[i][c] == candy[i + 1][c])
				i++;
			answer = max(answer, i - tmp + 1);
		}
	}
}

void row(int r) {	//가로
	int i, tmp;

	for (i = 0; i < n - 1; i++) {
		if (candy[r][i] == candy[r][i + 1]) {
			tmp = i;
			while (i < n - 1 && candy[r][i] == candy[r][i + 1])
				i++;
			answer = max(answer, i - tmp + 1);
		}
	}
}

int main() {
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> candy[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//아래
			if (i < n - 1) {
				swap(candy[i + 1][j], candy[i][j]);
				col(j);
				row(i);
				row(i + 1);
				swap(candy[i + 1][j], candy[i][j]);
			}

			//오른쪽
			if (j < n - 1) {
				swap(candy[i][j + 1], candy[i][j]);
				col(j);
				row(i);
				col(j + 1);
				swap(candy[i][j + 1], candy[i][j]);
			}
		}
	}

	printf("%d\n", answer);
}
