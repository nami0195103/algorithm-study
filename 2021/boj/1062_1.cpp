//완전탐색 - DFS(좀더빠름)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans;
vector<char> input[50];
bool available[26];

void solve(int idx, int cnt) {
	if (ans == n)
		return;

	if (cnt == k) {
		int i, j, tmp;
		bool flag;

		tmp = 0;
		for (i = 0; i < n; i++) {
			flag = true;
			for (j = 0; j < input[i].size(); j++) {
				if (!available[input[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				tmp++;
		}
		ans = max(tmp, ans);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (!available[i]) {
			available[i] = true;
			solve(i + 1, cnt + 1);
			available[i] = false;
		}
	}
}

int main() {
	int i, j, tmp;
	string str;
	bool flag;

	scanf("%d %d", &n, &k);
	if (k < 5) {
		printf("0\n");
		return 0;
	}
	else if (k == 26) {
		printf("%d\n", n);
		return 0;
	}

	k -= 5;
	for (i = 0; i < n; i++) {
		cin >> str;
		tmp = 0;
		for (j = 4; j < str.length() - 4; j++) {
			if (str[j] != 'a' && str[j] != 'n' && str[j] != 't' && str[j] != 'i' && str[j] != 'c')
				input[i].push_back(str[j]);
		}
	}

	ans = 0;
	available[0] = true;
	available['n' - 'a'] = true;
	available['t' - 'a'] = true;
	available['i' - 'a'] = true;
	available['c' - 'a'] = true;
	solve(0, 0);

	printf("%d\n", ans);
}
