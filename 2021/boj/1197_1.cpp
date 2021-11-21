//kruskal
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> rootnode;

bool comp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int get_rootnode(int a) {
	if (a == rootnode[a])
		return a;
	else {
		rootnode[a] = get_rootnode(rootnode[a]);
		return rootnode[a];
	}
}

bool find(int a, int b) {
	return get_rootnode(a) == get_rootnode(b);
}

void _union(int a, int b) {
	int v1, v2;

	v1 = get_rootnode(a);
	v2 = get_rootnode(b);

	if (v1 < v2) {
		rootnode[b] = v1;
		rootnode[v2] = v1;
	}
	else {
		rootnode[a] = v2;
		rootnode[v1] = v2;
	}
}

int main() {
	int v, e, i, j;
	vector<vector<int>> info;
	vector<int> tmp(3);
	long long ans = 0;

	scanf("%d %d", &v, &e);
	rootnode.resize(e + 1);
	for (i = 1; i <= e; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &tmp[j]);
		}
		info.push_back(tmp);
		rootnode[i] = i;
	}

	sort(info.begin(), info.end(), comp);
	
	for (i = 0; i < e; i++) {
		if (!find(info[i][0], info[i][1])) {
			_union(info[i][0], info[i][1]);
			ans += info[i][2];
		}
	}

	printf("%lld\n", ans);
}
