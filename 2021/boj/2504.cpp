//구현 - 스택 활용
//입력이 3^15까지 들어오므로 고려해서 짜야함 => stack<char> 로 짜면 오버플로우 남
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

enum parenthesis {
	sqbr_l = -4,
	sqbr_r = -3,
	par_l = -2,
	par_r = -1
};

int main() {
	string str;
	int i, res, val, pair;
	stack<int> st;
	parenthesis p;

	cin >> str;
	for (i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			st.push(par_l);
		else if (str[i] == '[')
			st.push(sqbr_l);
		else {
			if (str[i] == ')') {
				pair = par_l;
				val = 2;
			}
			else if (str[i] == ']') {
				pair = sqbr_l;
				val = 3;
			}
			res = 0;
			while (!st.empty() && st.top() != pair) {
				if (st.top() > 0) {
					res += st.top() * val;
					st.pop();
				}
				else {
					printf("0\n");
					return 0;
				}
			}
			if (st.empty()) {
				printf("0\n");
				return 0;
			}
			else {
				st.pop();
				if (res)
					st.push(res);
				else
					st.push(val);
			}
		}
	}

	res = 0;
	while (!st.empty()) {
		if (st.top() > 0) {
			res += st.top();
			st.pop();
		}
		else {
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n", res);
}
