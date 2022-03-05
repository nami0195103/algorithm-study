//단순구현
#include <iostream>
#include <string.h>
using namespace std;

#define print(i, j, c) if(shape[i][j]) printf("%c", c); \
						else printf(" ");

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

int main() {
	int s, i, j, k, len, num[11];
	char in[11];

	scanf("%d %s", &s, in);
	len = strlen(in);
	for (i = 0; i < len; i++) {
		num[i] = in[i] - '0';
	}

	//첫째줄
	for (i = 0; i < len; i++) {
		printf(" ");
		for (j = 0; j < s; j++) {
			print(num[i], 0, '-');
		}
		printf("  ");
	}
	printf("\n");

	//상부
	for (i = 0; i < s; i++) {
		for (j = 0; j < len; j++) {
			print(num[j], 1, '|');
			for (k = 0; k < s; k++)
				printf(" ");
			print(num[j], 2, '|');
			printf(" ");
		}
		printf("\n");
	}

	//가운데줄
	for (i = 0; i < len; i++) {
		printf(" ");
		for (j = 0; j < s; j++) {
			print(num[i], 3, '-');
		}
		printf("  ");
	}
	printf("\n");

	//하부
	for (i = 0; i < s; i++) {
		for (j = 0; j < len; j++) {
			print(num[j], 4, '|');
			for (k = 0; k < s; k++)
				printf(" ");
			print(num[j], 5, '|');
			printf(" ");
		}
		printf("\n");
	}

	//마지막줄
	for (i = 0; i < len; i++) {
		printf(" ");
		for (j = 0; j < s; j++) {
			print(num[i], 6, '-');
		}
		printf("  ");
	}
	printf("\n");

	return 0;
}
