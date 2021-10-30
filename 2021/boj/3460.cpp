//단순 구현
#include <iostream>
using namespace std;

int main() {
	int t, n, idx;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		idx = 0;
		while (n) {
			if (n % 2)
				printf("%d ", idx);
			idx++;
			n /= 2;
		}
		printf("\n");
	}
}
