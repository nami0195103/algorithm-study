//DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 987654321

int main() {
	int n, k, i, j;
	int dp[10001], coin[100];

	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 0;
	for (i = 1; i <= k; i++) {
		dp[i] = MAX;
		for (j = 0; j < n; j++) {
			if (coin[j] <= i) {
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}

	if (dp[k] == MAX)
		cout << -1 << endl;
	else
		cout << dp[k] << endl;

	return 0;
}
