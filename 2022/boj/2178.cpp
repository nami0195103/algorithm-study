// BFS
#include <iostream>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int n, m;
string maze[100];
bool isVisited[100][100];
typedef pair<pair<int, int>, int> myPair;	// ((r, c), cnt)
queue<myPair> q;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

#define check(pair) (pair.first >= 0 && pair.first < n && pair.second >= 0 && pair.second < m && maze[pair.first][pair.second] == '1')

myPair BFS() {
	int i;
	myPair mp, np = { {0, 0}, 0 };
	
	if (q.empty())
		return np;

	mp = q.front();
	q.pop();
	if (mp.first.first == n - 1 && mp.first.second == m - 1)
		return mp;

	for (i = 0; i < 4; i++) {
		np.first.first = mp.first.first + dy[i];
		np.first.second = mp.first.second + dx[i];
		np.second = mp.second + 1;

		if (check(np.first) && !isVisited[np.first.first][np.first.second]) {
			isVisited[np.first.first][np.first.second] = true;
			q.push(np);
		}
	}

	return BFS();
}

int main() {
	int i;
	myPair ans;

	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> maze[i];

	q.push(make_pair(make_pair(0, 0), 1));
	isVisited[0][0] = true;
	ans = BFS();
	cout << ans.second << endl;

	return 0;
}
