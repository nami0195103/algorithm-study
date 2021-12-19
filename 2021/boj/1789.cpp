//단순 구현
#include <iostream>
using namespace std;

int main() {
	unsigned int s, i, sum, n;

	scanf("%u", &s);
	sum = 0, i = 1;
	while (sum < s) {
		sum += i;
		if (s - sum <= i)
			break;
		i++;
	}
	printf("%u\n", i);
}
