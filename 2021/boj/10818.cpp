//단순구현 - vector, sort 사용할 수 있는데 메모리 시간 둘 다 많이씀
#include <iostream>
using namespace std;

int main() {
	int n, i;
	int min = 1000001;
	int max = -1000001;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &i);
		if (i < min)
			min = i;
		if (i > max)
			max = i;
	}

	printf("%d %d\n", min, max);
}
