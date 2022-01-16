//구현
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string carry(string str) {
	int i;

	for (i = 0; i < str.length() - 1; i++) {
		if (str[i] == str[i + 1]) {
			str[i + 1]++;
			str[i] = '0' + i;	//carry 발생 시 각 자릿수에 해당하는 수가 들어가야 함(각각 0123456789)
		}
	}
	if (str[i] == ':') {	//자릿수가 증가하는 경우
		str = "";
		for (int j = 0; j <= i + 1; j++) {
			str += '0' + j;	//0123456789 식으로 초기화
		}
	}

	return str;
}

string calc(int n) {
	int i;
	string ans;

	if (n <= 10)
		return to_string(n);
	else if (n > 1022)
		return "-1";
	else
		ans = "01";

	for (i = 11; i <= n; i++) {
		ans[0]++;
		ans = carry(ans);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	cin >> n;
	cout << calc(n) << endl;
}
