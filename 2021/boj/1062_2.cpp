//완전탐색 - 조합(코드 좀더 짧음)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans;
vector<char> input[50];
vector<bool> available(26);

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

	for (i = 0; i < k; i++) {
		available[25 - i] = true;
	}

	do {
		if (available[0] || available['n' - 'a'] || available['t' - 'a'] || available['i' - 'a'] || available['c' - 'a'])
			continue;

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
	} while (next_permutation(available.begin(), available.end()) && ans < n);

	printf("%d\n", ans);
}
