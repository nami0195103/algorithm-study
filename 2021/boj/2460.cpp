//단순 구현
#include <iostream>
using namespace std;

int main() {
	int n, i, j, cur = 0, ans = 0;

	for (n = 0; n < 10; n++) {
		scanf("%d %d", &i, &j);
		cur = cur - i + j;
		if (cur > ans)
			ans = cur;
	}

	printf("%d\n", ans);
}
