//단순 구현
#include <iostream>
using namespace std;

int main() {
	int a, b, i, j, tmp;

	scanf("%d %d", &a, &b);
	i = a, j = b;
	while (j) {
		tmp = j;
		j = i % j;
		i = tmp;
	}
	printf("%d %d\n", i, a * b / i);
}
