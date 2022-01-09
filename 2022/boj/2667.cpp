//BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j, tmpi, tmpj, cnt, ans1 = 0;
	string map[25];
	vector<int> ans2;
	queue<pair<int, int>> q;

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> map[i];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				cnt = 0, ans1++;
				q.push(make_pair(i, j));
				map[i][j] = '0';
				while (!q.empty()) {
					tmpi = q.front().first;
					tmpj = q.front().second;
					q.pop();
					cnt++;
					if (tmpi > 0 && map[tmpi - 1][tmpj] == '1') {	//위
						q.push(make_pair(tmpi - 1, tmpj));
						map[tmpi - 1][tmpj] = '0';
					}
					if (tmpi < n - 1 && map[tmpi + 1][tmpj] == '1') {	//아래
						q.push(make_pair(tmpi + 1, tmpj));
						map[tmpi + 1][tmpj] = '0';
					}
					if (tmpj > 0 && map[tmpi][tmpj - 1] == '1') {	//왼쪽
						q.push(make_pair(tmpi, tmpj - 1));
						map[tmpi][tmpj - 1] = '0';
					}
					if (tmpj < n - 1 && map[tmpi][tmpj + 1] == '1') {	//오른쪽
						q.push(make_pair(tmpi, tmpj + 1));
						map[tmpi][tmpj + 1] = '0';
					}
				}
				ans2.push_back(cnt);
			}
		}
	}

	sort(ans2.begin(), ans2.end());
	cout << ans1 << endl;
	for (i = 0; i < ans2.size(); i++)
		cout << ans2[i] << endl;
}
