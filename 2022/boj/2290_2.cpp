//단순구현 - 한줄출력/s줄출력 별로 함수 구현
#include <iostream>
#include <string.h>
using namespace std;

#define print(i, j, c) if(shape[i][j]) printf("%c", c); \
						else printf(" ");

int s, len, num[11];

bool shape[10][7] = { {true, true, true, false, true, true, true},	//0
	{false, false, true, false, false, true, false},
	{true, false, true, true, true, false, true},
	{true, false, true, true, false, true, true},
	{false, true, true, true, false, true, false},
	{true, true, false, true, false, true, true}, //5
	{true, true, false, true, true, true, true},
	{true, false, true, false, false, true, false},
	{true, true, true, true, true, true, true},
	{true, true, true, true, false, true, true}
};

void oneLine(int idx) {
	int i, j;

	for (i = 0; i < len; i++) {
		printf(" ");
		for (j = 0; j < s; j++) {
			print(num[i], idx, '-');
		}
		printf("  ");
	}
	printf("\n");
}

void sLine(int idx) {
	int i, j, k;

	for (i = 0; i < s; i++) {
		for (j = 0; j < len; j++) {
			print(num[j], idx, '|');
			for (k = 0; k < s; k++)
				printf(" ");
			print(num[j], idx + 1, '|');
			printf(" ");
		}
		printf("\n");
	}
}

int main() {
	char in[11];
	int i, j, k;

	scanf("%d %s", &s, in);
	len = strlen(in);
	for (i = 0; i < len; i++) {
		num[i] = in[i] - '0';
	}

	//첫째줄
	oneLine(0);

	//상부
	sLine(1);

	//가운데줄
	oneLine(3);

	//하부
	sLine(4);

	//마지막줄
	oneLine(6);

	return 0;
}
