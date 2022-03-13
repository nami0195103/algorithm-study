//완전탐색(dfs)
#include <iostream>
#include <string.h>
using namespace std;

int ans;
int in[6][3];
int cur[6][3];

void dfs(int c1, int c2) {
	int i, j, next1, next2;
	bool flag = true;

	if (ans == 1)
		return;
	else if (c2 == 6) {
		for (i = 0; i < 6 && flag; i++) {
			for (j = 0; j < 3 && flag; j++) {
				if (in[i][j] != cur[i][j])
					flag = false;
			}
		}

		if (flag)
			ans = 1;

		return;
	}

	//next c1, c2
	next2 = c2 + 1;
	if (next2 == 6) {
		next1 = c1 + 1;
		next2 = next1 + 1;
	}
	else
		next1 = c1;

	for (i = 0; i < 3; i++) {
		cur[c1][i]++;
		cur[c2][2 - i]++;

		for (j = 0; j < 3; j++) {
			if (cur[c1][j] > in[c1][j] || cur[c2][j] > in[c2][j])
				break;
		}
		if (j == 3)
			dfs(next1, next2);

		cur[c1][i]--;
		cur[c2][2 - i]--;
	}

	return;
}

int main() {
	int n = 4, i, j, sum;
	bool flag;

	while (n--) {
		flag = false;
		for (i = 0; i < 6; i++) {
			sum = 0;
			for (j = 0; j < 3; j++) {
				scanf("%d", &in[i][j]);
				if (in[i][j] == 6)
					flag = true;
				sum += in[i][j];
			}
			if (sum != 5)
				flag = true;
		}
		if (flag) {
			printf("0 ");
			continue;
		}

		memset(cur, 0, sizeof(cur));
		ans = 0;
		dfs(0, 1);
		printf("%d ", ans);
	}

	printf("\n");
	return 0;
}
