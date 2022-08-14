//DFS
#include <iostream>
using namespace std;

int n, m, sumW, sumB, cnt;
bool visited[102][102];
char arr[102][102];
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

void DFS(const char key, int r, int c) {
	if (r == m + 1 || c == n + 1)
		return;

	int nextR, nextC;

	for (int i = 0; i < 4; i++) {
		nextR = r + dirY[i];
		nextC = c + dirX[i];
		if (!visited[nextR][nextC] && arr[nextR][nextC] == key) {
			visited[nextR][nextC] = true;
			cnt++;
			DFS(key, nextR, nextC);
		}
	}

	return;
}

int main() {
	int i, j, sum;
	
	cin >> n >> m;

	for (i = 1; i <= m; i++)
		cin >> &arr[i][1];

	sum = 0;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				cnt = 1;
				DFS(arr[i][j], i, j);
				if (arr[i][j] == 'W')
					sumW += cnt * cnt;
				else
					sumB += cnt * cnt;
			}
		}
	}

	cout << sumW << " " << sumB << endl;

	return 0;
}
