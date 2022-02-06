//DFS
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int ans = 0, n, arr[17][17];

void calc(pair<int, int> p1, pair<int, int> p2) {
	if (p2.first == n && p2.second == n) {
		ans++;
		return;
	}

	if (p1.first == p2.first && p1.second + 1 == p2.second) {	//가로
		if (p2.second < n && !arr[p2.first][p2.second + 1]) {	//가로방향
			p1.second++, p2.second++;
			calc(p1, p2);
			p1.second--, p2.second--;
		}
		if (p2.first < n && p2.second < n && !arr[p2.first][p2.second + 1] && !arr[p2.first + 1][p2.second + 1] && !arr[p2.first + 1][p2.second]) {	//대각선방향
			p1.second++, p2.first++, p2.second++;
			calc(p1, p2);
			p1.second--, p2.first--, p2.second--;
		}
	}
	else if (p1.first + 1 == p2.first && p1.second == p2.second) {	//세로
		if (p2.first < n && !arr[p2.first + 1][p2.second]) {	//세로방향
			p1.first++, p2.first++;
			calc(p1, p2);
			p1.first--, p2.first--;
		}
		if (p2.first < n && p2.second < n && !arr[p2.first][p2.second + 1] && !arr[p2.first + 1][p2.second + 1] && !arr[p2.first + 1][p2.second]) {	//대각선방향
			p1.first++, p2.first++, p2.second++;
			calc(p1, p2);
			p1.first--, p2.first--, p2.second--;
		}
	}
	else {	//대각선
		if (p2.second < n && !arr[p2.first][p2.second + 1]) {	//가로방향
			p1.first++, p1.second++, p2.second++;
			calc(p1, p2);
			p1.first--, p1.second--, p2.second--;
		}
		if (p2.first < n && !arr[p2.first + 1][p2.second]) {	//세로방향
			p1.first++, p1.second++, p2.first++;
			calc(p1, p2);
			p1.first--, p1.second--, p2.first--;
		}
		if (p2.first < n && p2.second < n && !arr[p2.first][p2.second + 1] && !arr[p2.first + 1][p2.second + 1] && !arr[p2.first + 1][p2.second]) {	//대각선방향
			p1.first++, p1.second++, p2.first++, p2.second++;
			calc(p1, p2);
			p1.first--, p1.second--, p2.first--, p2.second--;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;

	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> arr[i][j];

	calc(make_pair(1, 1), make_pair(1, 2));
	cout << ans << endl;

	return 0;
}
