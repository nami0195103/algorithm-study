//단순 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, i;
	vector<int> a(10);

	scanf("%d", &t);
	while (t--) {
		for (i = 0; i < 10; i++)
			scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		printf("%d\n", a[7]);
	}
}
