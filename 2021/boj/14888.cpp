//구현 - 완전탐색(조합)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _min = 100000000, _max = -100000000;

void calculate(vector<int> &arr, vector<int> &op) {
	int res = arr[0];
	int i;

	for (i = 0; i < op.size(); i++) {
		switch (op[i]) {
		case 0:
			res += arr[i + 1];
			break;
		case 1:
			res -= arr[i + 1];
			break;
		case 2:
			res *= arr[i + 1];
			break;
		case 3:
			res /= arr[i + 1];
			break;
		}
	}
	
	_min = min(_min, res);
	_max = max(_max, res);
}

int main() {
	int n, i, j;
	vector<int> arr, op;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &j);
		arr.push_back(j);
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &j);
		while (j--)
			op.push_back(i);
	}
	
	do {
		calculate(arr, op);
	} while (next_permutation(op.begin(), op.end()));

	printf("%d\n%d\n", _max, _min);
}
