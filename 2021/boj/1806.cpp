//투포인터
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, s, arr[100000], i, j, ans, left, right, sum;

	ans = 0;
	scanf("%d %d", &n, &s);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		ans += arr[i];
	}

	if (ans < s) {
		printf("0\n");
		return 0;
	}

	ans = 987654321;
	left = sum = 0;
	for (right = 0; right < n && sum < s; right++)	//합 >= S 되도록 right++
		sum += arr[right];
	ans = min(ans, right - left);

	while (right <= n) {
		while (sum >= s && left < right) {	//합 < S 되도록 left++
			sum -= arr[left++];
		}
		ans = min(ans, right - left + 1);
		sum += arr[right++];
	}

	printf("%d\n", ans);
}
