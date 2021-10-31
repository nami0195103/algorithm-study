//단순 구현
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int m, n, i, j, sum = 0, min = 12345;
	bool flag;

	scanf("%d %d", &m, &n);
	if (m == 1)
		m++;
	for (i = m; i <= n; i++) {
		flag = true;
		for (j = 2; j <= sqrt(i); j++) {
			if (!(i % j)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			sum += i;
			if (i < min)
				min = i;
		}
	}

	if (!sum)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);
}
