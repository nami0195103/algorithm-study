//단순 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k, sum = 0;
	vector<int> in;

	for (i = 0; i < 9; i++) {
		scanf("%d", &k);
		in.push_back(k);
		sum += k;
	}
	sort(in.begin(), in.end());
	
	k = 0;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - in[i] - in[j] == 100) {
				for (k = 0; k < 9; k++) {
					if (k != i && k != j)
						printf("%d\n", in[k]);
				}
				break;
			}
		}
		if (k == 9)
			break;
	}
}
