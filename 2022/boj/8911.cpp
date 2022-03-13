//단순구현
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int T, i, tmp;
	char in[510];
	pair<int, int> maxx, minn, cur, dir;

	scanf("%d", &T);
	while (T--) {
		cur = make_pair(0, 0);
		dir = make_pair(0, 1);
		maxx = cur;
		minn = cur;

		scanf("%s", in);
		for (i = 0; in[i] != '\0'; i++) {
			switch (in[i]) {
			case 'F':
				cur.first += dir.first;
				cur.second += dir.second;
				break;
			case 'B':
				cur.first -= dir.first;
				cur.second -= dir.second;
				break;
			case 'R':
				tmp = dir.first;
				dir.first = dir.second;
				dir.second = -1 * tmp;
				break;
			case 'L':
				tmp = dir.first;
				dir.first = -1 * dir.second;
				dir.second = tmp;
				break;
			}

			maxx.first = max(maxx.first, cur.first);
			maxx.second = max(maxx.second, cur.second);
			minn.first = min(minn.first, cur.first);
			minn.second = min(minn.second, cur.second);
		}

		printf("%d\n", (maxx.first - minn.first) * (maxx.second - minn.second));
	}
}
