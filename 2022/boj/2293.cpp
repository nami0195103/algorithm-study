//DP - 솔루션 보고 풂 나중에 다시 풀기!!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, i, j;
	vector<int> a;
	vector<int> DP;

	scanf("%d %d", &n, &k);
	a.assign(n, 0);
	DP.assign(k + 1, 0);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	DP[0] = 1;
	for (i = 0; i < n; i++) {
		for (j = a[i]; j <= k; j++) {
			DP[j] += DP[j - a[i]];
		}
	}
	printf("%d\n", DP[k]);

	return 0;
}
