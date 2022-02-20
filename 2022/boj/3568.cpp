//단순구현
#include <iostream>
using namespace std;

int main() {
	char in[122];
	char type[120], name[120], opt[120];	//기본 변수형, 변수명, 추가적인 변수형
	int i, idx;

	fgets(in, 122, stdin);

	i = 0;
	while (in[i] != ' ') {
		type[i] = in[i];
		i++;
	}
	type[i++] = '\0';

	while (in[i] != '\0') {	//마지막에 ";\n"을 skip하므로 '\0'을 가리키고 있음
		idx = 0;
		while ((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z'))
			name[idx++] = in[i++];
		name[idx] = '\0';

		idx = 0;
		while (in[i] != ',' && in[i] != ';') {
			opt[idx++] = in[i++];
		}
		i += 2;	//", " skip

		printf("%s", type);
		while (idx > 0) {
			idx--;
			if (opt[idx] == ']') {
				printf("[]");
				idx--;
			}
			else
				printf("%c", opt[idx]);
		}
		printf(" %s;\n", name);
	}

	return 0;
}
