//완전탐색 - dfs
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans = 987654321;
int order[100], arr[100];

void dfs(int mul, int elec, int cnt) {
	if (ans <= cnt)
		return;
	if (elec == k) {
		ans = min(ans, cnt);
		return;
	}

	int i, tmp;
	bool flag = false;
	
	for (i = 0; i < mul; i++) {
		if (arr[i] == order[elec]) {
			flag = true;
			break;
		}
	}
	if (flag)
		dfs(mul, elec + 1, cnt);
	else if (mul < n) {
		arr[mul] = order[elec];
		dfs(mul + 1, elec + 1, cnt);
	}
	else {
		for (i = 0; i < mul; i++) {
			tmp = arr[i];
			arr[i] = order[elec];
			dfs(mul, elec + 1, cnt + 1);
			arr[i] = tmp;
		}
	}
}

int main() {
	int i;

	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++)
		scanf("%d", &order[i]);

	dfs(0, 0, 0);

	printf("%d\n", ans);
}
