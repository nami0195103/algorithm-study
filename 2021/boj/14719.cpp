//단순 구현 - 완전탐색
#include <iostream>
using namespace std;

int main() {
	int h, w, i, j, ans = 0, tmp;
	int arr[500];
	
	scanf("%d %d", &h, &w);
	for (i = 0; i < w; i++)
		scanf("%d", &arr[i]);

	for (i = 1; i <= h; i++) {
		j = 0;
		while (j < w && arr[j] < i)
			j++;
		j++;
		do {
			tmp = j;
			while (j < w && arr[j] < i)
				j++;
			if (j < w && arr[j] >= i)
				ans += j - tmp;
			j++;
		} while (j < w);
	}

	printf("%d\n", ans);
}
