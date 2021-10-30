//단순 구현
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, i, cnt = 0;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		if (!(n % i)) {
			if (++cnt == k) {
				printf("%d\n", i);
				break;
			}
		}
	}

	if (cnt < k)
		printf("0\n");
}
