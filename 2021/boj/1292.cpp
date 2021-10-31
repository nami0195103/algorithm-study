//단순 구현
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, i, end, start = 1, sum = 0;

	scanf("%d %d", &a, &b);
	for (i = 1; start <= b; i++) {
		if (start <= a && a < start + i) {
			end = min(b, start + i - 1);
			sum += i * (end - a + 1);
		}
		else if (start > a) {
			end = min(b, start + i - 1);
			sum += i * (end - start + 1);
		}
		start += i;
	}

	printf("%d\n", sum);
}
