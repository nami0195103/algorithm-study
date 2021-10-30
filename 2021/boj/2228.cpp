//dp - 나중에 다시 풀어보기!
#include <iostream>
#include <queue>
using namespace std;

#define MIN -987654321

int arr[101];
int dp[101][51];

int main() {
	int n, m;
	int i, j, k;
	int sum, tmp;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 1; i <= n; i++)
		dp[0][i] = MIN;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			sum = 0;
			for (k = i; k > 0; k--) {
				sum += arr[k];
				if (k >= 2)
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum);
				else if (k == 1 && j == 1)
					dp[i][j] = max(dp[i][j], sum);
			}
		}
	}

	printf("%d\n", dp[n][m]);

	return 0;
}
