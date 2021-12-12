//KMP
#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 1000001
int f[MAXLEN];
string s, p;

void fail() {
	int i, j, n = p.length();

	f[0] = -1;
	for (j = 1; j < n; j++) {
		i = f[j - 1];
		while (p[i + 1] != p[j] && i >= 0)
			i = f[i];
		if (p[i + 1] == p[j])
			f[j] = i + 1;
		else
			f[j] = -1;
	}
}

int pmatch() {
	int i, j, lens, lenp;

	lens = s.length();
	lenp = p.length();
	i = 0, j = 0;

	while (i < lens && j < lenp) {
		if (s[i] == p[j])
			i++, j++;
		else if (j == 0)
			i++;
		else
			j = f[j - 1] + 1;
	}

	if (j == lenp)
		return 1;
	else
		return 0;
}

int main() {
	cin >> s >> p;
	fail();
	printf("%d\n", pmatch());
}
