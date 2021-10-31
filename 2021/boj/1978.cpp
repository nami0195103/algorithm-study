//단순 구현
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, i, j, cnt = 0;
	vector<bool> p(1001);

	for (i = 2; i <= 1000; i++) {
		p[i] = true;
		for (j = 2; j <= sqrt(i); j++) {
			if (!(i % j)) {
				p[i] = false;
				break;
			}
		}
	}

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &i);
		if (p[i])
			cnt++;
	}

	printf("%d\n", cnt);
}
