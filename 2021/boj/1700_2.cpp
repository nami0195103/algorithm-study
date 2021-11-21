//단순구현 - 다시 안 쓰이는/가장 나중에 다시 꼽히는 기기를 먼저 뺌
//DFS보다 빠름
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int order[100], multitap[100], n, k, cnt = 0;
	int i, j, l, m, last, idx;
	bool flag;

	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++)
		scanf("%d", &order[i]);

	m = 0;
	for (i = 0; i < k; i++) {
		flag = false;
		for (j = 0; j < m; j++) {
			if (multitap[j] == order[i]) {
				flag = true;
				break;
			}
		}

		if (flag)	//멀티탭에 이미 있는 경우
			continue;
		else if (m < n) {	//멀티탭에 없지만 자리가 있는 경우
			multitap[m] = order[i];
			m++;
		}
		else {	//멀티탭에 없도 자리도 없는 경우
			last = 0, idx = 0;	//첫번째기기(3순위)
			for (j = 0; j < m; j++) {
				flag = true;
				for (l = i + 1; l < k; l++) {
					if (multitap[j] == order[l]) {
						flag = false;
						if (last < l) {	//order에 있으면서 가장 나중에 다시 꼽히는 기기(2순위)
							last = l;
							idx = j;
						}
						break;
					}
				}
				if (flag) {	//order에 없는 기기(1순위)
					idx = j;
					break;
				}
			}
			multitap[idx] = order[i];
			cnt++;
		}
	}

	printf("%d\n", cnt);
}
