//DFS, BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

vector<int> connected[1001];
int n, m, start;
bool visited[1001];


void DFS(int start) {
	int i;

	cout << start << " ";

	for (i = 0; i < connected[start].size(); i++) {
		if (!visited[connected[start][i]]) {
			visited[connected[start][i]] = true;
			DFS(connected[start][i]);
		}
	}

	return;
}

void BFS(queue<int>& q) {
	if (q.empty())
		return;

	int start = q.front();
	int i;
	
	q.pop();
	cout << start << " ";
	
	for (i = 0; i < connected[start].size(); i++) {
		if (!visited[connected[start][i]]) {
			visited[connected[start][i]] = true;
			q.push(connected[start][i]);
		}
	}

	BFS(q);

	return;
}

int main() {
	int i, j, k;
	queue<int> q;

	cin >> n >> m >> start;
	for (i = 0; i < m; i++) {
		cin >> j >> k;
		connected[j].push_back(k);
		connected[k].push_back(j);
	}

	for (i = 0; i <= n; i++) {
		if (connected[i].size() > 1)
			sort(connected[i].begin(), connected[i].end());
	}

	visited[start] = true;
	DFS(start);
	cout << endl;

	q.push(start);
	memset(visited, 0, sizeof(visited));
	visited[start] = true;
	BFS(q);
	cout << endl;

	return 0;
}
