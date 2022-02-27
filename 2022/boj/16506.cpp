#include <iostream>
#include <string>
#include <string.h>
#include <bitset>
using namespace std;

char opcode[12][6] = { "ADD", "SUB", "MOV", "AND", "OR", "NOT", "MULT", "LSFTL", "LSFTR", "ASFTR", "RL", "RR" };

string translate(char* ptr, bool& isConstant) {
	string str = "";
	bitset<4> bs;

	for (int i = 0; i < 12; i++) {
		if (!strncmp(ptr, opcode[i], strlen(opcode[i]))) {
			bs = i;
			str = bs.to_string();
			if (strlen(ptr) > strlen(opcode[i])) {
				str += '1';
				isConstant = true;
			}
			else {
				str += '0';
				isConstant = false;
			}
			break;
		}
	}

	str += '0';
	return str;
}

int main() {
	int n;
	char str[17];
	char* ptr;
	bool isConstant = false;
	bitset<4> bs;
	string answer;

	scanf("%d", &n);
	fgetc(stdin);

	while (n--) {
		fgets(str, 17, stdin);

		//bit 0~5
		ptr = strtok(str, " ");
		answer = translate(ptr, isConstant);

		//bit 6~8, 9~11, 12~15
		for (int i = 0; i < 3; i++) {
			ptr = strtok(NULL, " ");
			bs = stoi(ptr);

			if (i == 2 && isConstant) {
				answer += bs.to_string();
			}
			else {
				answer += bs.to_string().substr(1);
				if (i == 2)
					answer += '0';
			}
		}

		cout << answer << '\n';
	}
}
