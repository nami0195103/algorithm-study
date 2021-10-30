//단순 구현
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, i, ans;
	vector<int> p;

	scanf("%d", &n);
	p.push_back(0);
	p.push_back(1);
	for (i = 2; i <= n; i++) {
		p.push_back(p[i - 2] + p[i - 1]);
	}
	printf("%d\n", p[n]);
}
