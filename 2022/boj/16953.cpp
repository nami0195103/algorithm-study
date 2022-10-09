//DFS
#include <iostream>
using namespace std;

#define MAX_ANS 987654321

long long a, b;
int ans = MAX_ANS;

void dfs(long long k, int cnt) {
	if (k >= 1000000000 || k > b)	//10^9
		return;

	if (k * 2 == b) {
		ans = cnt + 1 < ans ? cnt + 1 : ans;
		return;
	}
	else
		dfs(k * 2, cnt + 1);

	if (10 * k + 1 == b)
		ans = cnt + 1 < ans ? cnt + 1 : ans;
	else
		dfs(10 * k + 1, cnt + 1);

	return;
}

int main() {
	cin >> a >> b;
	dfs(a, 0);

	if (ans == MAX_ANS)
		ans = -1;
	else
		ans++;

	cout << ans << '\n';
}
